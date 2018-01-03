// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/is_equal.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_is_equal, different_size)
{
    std::vector<uint8_t> d1(10);
    std::vector<uint8_t> d2(11);

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_equal, different_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'b');

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_equal, same_size_and_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'a');

    EXPECT_TRUE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_equal(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_equal, different_size_same_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(9, 'a');

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
}

TEST(test_is_equal, different_storage_types)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'a');
    storage::const_storage s1 = storage::storage(d1);
    storage::mutable_storage s2 = storage::storage(d2);

    EXPECT_TRUE(storage::is_equal(s1, s2));
}
