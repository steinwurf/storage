// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/operator_equal.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_operator_equal, equal)
{
    std::vector<uint8_t> d1(10, 1);
    std::vector<uint8_t> d2(10, 2);
    std::vector<uint8_t> d3(15, 1);
    std::vector<uint8_t> d3_2(15, 1);

    EXPECT_EQ(storage::storage(d1), storage::storage(d1));
    EXPECT_NE(storage::storage(d1), storage::storage(d2));
    EXPECT_NE(storage::storage(d1), storage::storage(d3));
    EXPECT_NE(storage::storage(d1), storage::storage(d3_2));
    EXPECT_EQ(storage::storage(d3), storage::storage(d3_2));
}
