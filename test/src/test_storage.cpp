// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/storage.hpp>

#include <cstdint>
#include <vector>
#include <iterator>

#include <gtest/gtest.h>

template<class PodType>
static void test_vector_helper(uint32_t vector_size)
{
    std::vector<PodType> v(vector_size);

    storage::const_storage cs = storage::storage(v);
    EXPECT_EQ(cs.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast_storage<PodType>(cs), &v[0]);
    EXPECT_EQ(std::distance(cs.begin(), cs.end()), 1);

    storage::mutable_storage ms = storage::storage(v);
    EXPECT_EQ(ms.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast_storage<PodType>(ms), &v[0]);
    EXPECT_EQ(std::distance(ms.begin(), ms.end()), 1);

    // Check const
    const std::vector<PodType>& v_ref = v;

    storage::const_storage const_cs = storage::storage(v_ref);
    EXPECT_EQ(const_cs.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast_storage<PodType>(const_cs), &v_ref[0]);
    EXPECT_EQ(std::distance(const_cs.begin(), const_cs.end()), 1);
}

TEST(TestStorage, test_storage_function_vector)
{
    uint32_t size = rand() % 100000;
    test_vector_helper<char>(size);
    test_vector_helper<short>(size);
    test_vector_helper<int>(size);
    test_vector_helper<uint8_t>(size);
    test_vector_helper<uint16_t>(size);
    test_vector_helper<uint32_t>(size);
    test_vector_helper<uint64_t>(size);
}

template<class PodType>
static void test_buffer_helper(uint32_t vector_size)
{
    std::vector<PodType> v(vector_size);

    PodType* v_data = &v[0];
    uint32_t v_size = vector_size * sizeof(PodType);

    storage::const_storage cs = storage::storage(v_data, v_size);
    EXPECT_EQ(cs.m_size, v_size);
    EXPECT_EQ(storage::cast_storage<PodType>(cs), &v_data[0]);
    EXPECT_EQ(std::distance(cs.begin(), cs.end()), 1);

    storage::mutable_storage ms = storage::storage(v_data, v_size);
    EXPECT_EQ(ms.m_size, v_size);
    EXPECT_EQ(storage::cast_storage<PodType>(ms), &v_data[0]);
    EXPECT_EQ(std::distance(ms.begin(), ms.end()), 1);

    // Check const
    const PodType* v_data_const = v_data;

    storage::const_storage const_cs = storage::storage(v_data_const, v_size);
    EXPECT_EQ(const_cs.m_size, v_size);
    EXPECT_EQ(storage::cast_storage<PodType>(const_cs), &v_data_const[0]);
    EXPECT_EQ(std::distance(const_cs.begin(), const_cs.end()), 1);
}

TEST(TestStorage, test_storage_function_buffer)
{
    uint32_t size = rand() % 100000;
    test_buffer_helper<char>(size);
    test_buffer_helper<short>(size);
    test_buffer_helper<int>(size);
    test_buffer_helper<uint8_t>(size);
    test_buffer_helper<uint16_t>(size);
    test_buffer_helper<uint32_t>(size);
    test_buffer_helper<uint64_t>(size);
}

TEST(TestStorage, test_mutable_to_const_conversion)
{
    uint32_t size = 500;
    std::vector<uint8_t> v(size);

    storage::mutable_storage ms = storage::storage(v);
    storage::const_storage cs = ms;
    cs = ms;
}

TEST(TestStorage, test_split_storage)
{
    uint32_t size = 500;
    uint32_t split = 100;
    std::vector<uint8_t> v(size);

    auto storage = storage::storage(v);
    auto storage_sequence = storage::split_storage(storage, split);

    EXPECT_EQ(storage_sequence.size(), 5U);
    for (uint32_t i = 0; i < storage_sequence.size(); ++i)
    {
        EXPECT_EQ(storage_sequence[i].m_size, split);
    }

    EXPECT_EQ(500U, storage::storage_size(
        storage_sequence.begin(), storage_sequence.end()));
}

TEST(TestStorage, test_offset_storage)
{
    {
        uint32_t size = 500;
        uint32_t split = 100;
        std::vector<uint8_t> v(size);

        storage::mutable_storage old_storage = storage::storage(v);

        auto new_storage = old_storage + split;
        EXPECT_EQ(new_storage.m_size, 400U);
        EXPECT_EQ(new_storage.m_data, &v[100]);

        new_storage += 100;
        EXPECT_EQ(new_storage.m_size, 300U);
        EXPECT_EQ(new_storage.m_data, &v[200]);
    }

    {
        uint32_t size = 500;
        uint32_t split = 100;
        std::vector<uint8_t> v(size);

        storage::const_storage old_storage = storage::storage(v);

        auto new_storage = old_storage + split;
        EXPECT_EQ(new_storage.m_size, 400U);
        EXPECT_EQ(new_storage.m_data, &v[100]);

        new_storage += 100;
        EXPECT_EQ(new_storage.m_size, 300U);
        EXPECT_EQ(new_storage.m_data, &v[200]);
    }
}

TEST(TestStorage, is_equal)
{
    {
        std::vector<uint8_t> d1(10);
        std::vector<uint8_t> d2(11);

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(10, 'b');

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(10, 'a');

        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(9, 'a');

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        auto d2 = storage::storage(d1);
        EXPECT_TRUE(storage::is_equal(storage::storage(d1), d2));
        d2 += 2;

        EXPECT_FALSE(storage::is_equal(storage::storage(d1), d2));
    }
}

TEST(TestStorage, is_same)
{
    {
        std::vector<uint8_t> d1(10);
        std::vector<uint8_t> d2(11);

        EXPECT_FALSE(
            storage::is_same(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(10, 'b');

        EXPECT_FALSE(
            storage::is_same(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(10, 'a');

        EXPECT_FALSE(
            storage::is_same(storage::storage(d1), storage::storage(d2)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d1), storage::storage(d1)));
        EXPECT_TRUE(
            storage::is_same(storage::storage(d2), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(9, 'a');

        EXPECT_FALSE(
            storage::is_same(storage::storage(d1), storage::storage(d2)));
    }

    {
        std::vector<uint8_t> d1(10, 'a');
        auto d2 = storage::storage(d1);
        EXPECT_TRUE(storage::is_same(storage::storage(d1), d2));
        d2 += 2;

        EXPECT_FALSE(storage::is_same(storage::storage(d1), d2));
    }
}

TEST(TestStorage, test_copy_storage)
{
    {
        std::vector<uint8_t> d1(10, 'a');
        std::vector<uint8_t> d2(10, 'b');

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));

        // Copy the contents of d1 to d2
        storage::copy_storage(storage::storage(d2), storage::storage(d1));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
        // Zero the contents of d2
        storage::zero_storage(storage::storage(d2));
        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));

        // d3 will be zero-initialized
        std::vector<uint8_t> d3(10);
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d2), storage::storage(d3)));
    }

    {
        std::vector<uint8_t> d1(10, 'x');
        std::vector<uint8_t> d2(11, 'y');

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));

        // copy_storage should work even though d2 is larger than d1,
        // but they will not be equal, since their sizes do not match
        storage::copy_storage(storage::storage(d2), storage::storage(d1));

        EXPECT_FALSE(
            storage::is_equal(storage::storage(d1), storage::storage(d2)));
        // Offset the first byte of d2, so they should be equal
        storage::zero_storage(storage::storage(d2));
        storage::copy_storage(storage::storage(d2) + 1, storage::storage(d1));
        EXPECT_TRUE(
            storage::is_equal(storage::storage(d1), storage::storage(d2) + 1));
    }
}

/// Test that we can convert a non-const std::string to a
/// storage::mutable_storage object
TEST(TestStorage, convert_string)
{
    std::string str("test");
    storage::mutable_storage m = storage::storage(str);
    EXPECT_EQ(str.size(), m.m_size);
    EXPECT_EQ((uint8_t*) str.data(), m.m_data);
}

/// Test that we can convert a const std::string to storage::const_storage
/// object
TEST(TestStorage, convert_const_string)
{
    const std::string str("test");
    storage::const_storage c = storage::storage(str);
    EXPECT_EQ(str.size(), c.m_size);
    EXPECT_EQ((uint8_t*) str.data(), c.m_data);
}
