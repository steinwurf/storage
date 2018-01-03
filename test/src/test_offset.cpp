// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/offset.hpp>
#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_offset, api)
{
    std::vector<uint8_t> data {0xFF, 0xEE, 0xDD, 0xCC };
    auto storage = storage::storage(data);

    EXPECT_EQ(4U, storage.size());
    storage = storage::offset(storage, 2);

    EXPECT_EQ(2U, storage.size());
    EXPECT_EQ(0xDDU, storage.data()[0]);
    EXPECT_EQ(0xCCU, storage.data()[1]);
}
