// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/slice.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_slice, api)
{
    std::vector<uint8_t> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto storage = storage::storage(data);
    EXPECT_EQ(data.size(), storage.size());

    uint32_t offset = 4;
    uint32_t new_size = 4;
    storage = storage::slice(storage, offset, new_size);
    std::vector<uint8_t> new_data { 4, 5, 6, 7 };
    auto expected_storage = storage::storage(new_data);
    EXPECT_EQ(expected_storage, storage);
}
