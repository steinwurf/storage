// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/shrink.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_shrink, api)
{
    std::vector<uint8_t> data(10);
    auto storage = storage::storage(data);
    EXPECT_EQ(data.size(), storage.size());

    uint32_t new_size = 4;
    storage = storage::shrink(storage, new_size);
    EXPECT_EQ(new_size, storage.size());
}
