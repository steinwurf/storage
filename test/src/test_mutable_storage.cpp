// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/mutable_storage.hpp>

#include <storage/storage.hpp>

#include <cstdint>
#include <vector>
#include <iterator>

#include <gtest/gtest.h>

TEST(test_mutable_storage, test_mutable_to_const_conversion)
{
    uint32_t size = 500;
    std::vector<uint8_t> v(size);

    storage::mutable_storage ms = storage::storage(v);
    storage::const_storage cs = ms;
    cs = ms;
}

TEST(test_mutable_storage, test_offset_storage)
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

/// Test that we can convert a non-const std::string to a
/// storage::mutable_storage object
TEST(test_mutable_storage, convert_string)
{
    std::string str("test");
    storage::mutable_storage m = storage::storage(str);
    EXPECT_EQ(str.size(), m.m_size);
    EXPECT_EQ((uint8_t*) str.data(), m.m_data);
}
