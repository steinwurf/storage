// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/storage.hpp>
#include <storage/cast.hpp>

#include <cstdint>
#include <vector>
#include <iterator>

#include <gtest/gtest.h>

template<class PodType>
static void test_vector_helper(uint32_t vector_size)
{
    std::vector<PodType> v(vector_size);

    storage::const_storage cs = storage::storage(v);
    EXPECT_EQ(cs.size(), vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast<PodType>(cs), &v[0]);

    storage::mutable_storage ms = storage::storage(v);
    EXPECT_EQ(ms.size(), vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast<PodType>(ms), &v[0]);

    // Check const
    const std::vector<PodType>& v_ref = v;

    storage::const_storage const_cs = storage::storage(v_ref);
    EXPECT_EQ(const_cs.size(), vector_size * sizeof(PodType));
    EXPECT_EQ(storage::cast<PodType>(const_cs), &v_ref[0]);
}

TEST(test_storage, test_vector_helper)
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
static void test_buffer_helper(uint32_t buffer_size)
{
    std::vector<PodType> buffer(buffer_size);

    PodType* data = buffer.data();
    uint32_t size = buffer.size() * sizeof(PodType);

    storage::const_storage const_storage = storage::storage(data, size);
    EXPECT_EQ(const_storage.size(), size);
    EXPECT_EQ(storage::cast<PodType>(const_storage), &data[0]);

    storage::mutable_storage mutable_storage = storage::storage(data, size);
    EXPECT_EQ(mutable_storage.size(), size);
    EXPECT_EQ(storage::cast<PodType>(mutable_storage), &data[0]);

    // Check const
    const PodType* const_data = data;

    storage::const_storage const_storage2 = storage::storage(const_data, size);
    EXPECT_EQ(const_storage2.size(), size);
    EXPECT_EQ(storage::cast<PodType>(const_storage2), &const_data[0]);
}

TEST(test_storage, test_buffer_helper)
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
