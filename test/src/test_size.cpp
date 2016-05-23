// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/size.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>
#include <iterator>

#include <gtest/gtest.h>

TEST(test_size, api)
{
    uint32_t size = 500;
    std::vector<uint8_t> v(size);

    auto storage = storage::storage(v);

    EXPECT_EQ(size, storage::size(storage.begin(), storage.end()));
}