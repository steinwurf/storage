// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/storage.hpp>
#include <storage/split.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_split, api)
{
    uint32_t size = 550;
    uint32_t split = 100;
    std::vector<uint8_t> v(size);

    auto storage = storage::storage(v);
    auto storage_sequence = storage::split(storage, split);

    EXPECT_EQ(6U, storage_sequence.size());
    for (uint32_t i = 0; i < storage_sequence.size() - 1; ++i)
    {
        EXPECT_EQ(split, storage_sequence[i].size());
    }

    EXPECT_EQ(50U, storage_sequence[storage_sequence.size() - 1].size());

}
