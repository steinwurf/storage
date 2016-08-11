// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/const_storage.hpp>
#include <storage/storage.hpp>

#include <gtest/gtest.h>

#include <string>
#include <cstdint>
#include <vector>

/// Test that we can convert a const std::string to storage::const_storage
/// object
TEST(test_const_storage, convert_const_string)
{
    const std::string str("test");
    storage::const_storage c = storage::storage(str);
    EXPECT_EQ(str.size(), c.m_size);
    EXPECT_EQ((uint8_t*) str.data(), c.m_data);
}

TEST(test_const_storage, test_offset_storage)
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

TEST(test_const_storage, test_operator_equal)
{
    uint32_t size = 100;
    std::vector<uint8_t> a(size);
    std::vector<uint8_t> b(size-1);

    std::generate(std::begin(a), std::end(a), rand);
    std::generate(std::begin(b), std::end(b), rand);

    EXPECT_TRUE(storage::storage(a) == storage::storage(a));
    EXPECT_TRUE(storage::storage(b) == storage::storage(b));
    EXPECT_FALSE(storage::storage(a) == storage::storage(b));

}
