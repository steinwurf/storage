// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/storage.hpp>
#include <storage/copy.hpp>
#include <storage/is_equal.hpp>
#include <storage/fill_zero.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_copy, same_size)
{
    std::vector<uint8_t> d1(10, 'a');
    std::vector<uint8_t> d2(10, 'b');

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));

    // Copy the contents of d1 to d2
    storage::copy(storage::storage(d2), storage::storage(d1));
    EXPECT_TRUE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
    // Zero the contents of d2
    storage::fill_zero(storage::storage(d2));
    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));

    // d3 will be zero-initialized
    std::vector<uint8_t> d3(10);
    EXPECT_TRUE(storage::is_equal(storage::storage(d2), storage::storage(d3)));
}

TEST(test_copy, not_same_size)
{
    std::vector<uint8_t> d1(10, 'x');
    std::vector<uint8_t> d2(11, 'y');

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));

    // copy_storage should work even though d2 is larger than d1,
    // but they will not be equal, since their sizes do not match
    storage::copy(storage::storage(d2), storage::storage(d1));

    EXPECT_FALSE(storage::is_equal(storage::storage(d1), storage::storage(d2)));
}

