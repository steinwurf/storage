// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/is_same.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_is_same, different_size)
{
    std::vector<uint8_t> d1(10);
    std::vector<uint8_t> d2(11);

    EXPECT_FALSE(storage::is_same(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_same(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_same(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_same, different_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'b');

    EXPECT_FALSE(storage::is_same(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_same(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_same(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_same, same_size_and_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'a');

    EXPECT_FALSE(storage::is_same(storage::storage(d1), storage::storage(d2)));
    EXPECT_TRUE(storage::is_same(storage::storage(d1), storage::storage(d1)));
    EXPECT_TRUE(storage::is_same(storage::storage(d2), storage::storage(d2)));
}

TEST(test_is_same, different_size_same_content)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(9, 'a');

    EXPECT_FALSE(storage::is_same(storage::storage(d1), storage::storage(d2)));
}

TEST(test_is_same, change_conetent)
{
    std::vector<uint8_t> d1(10, 'a');
    auto d2 = storage::storage(d1);
    EXPECT_TRUE(storage::is_same(storage::storage(d1), d2));
    d2 += 2;

    EXPECT_FALSE(storage::is_same(storage::storage(d1), d2));
}