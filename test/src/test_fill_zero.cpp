// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/fill_zero.hpp>
#include <storage/storage.hpp>
#include <storage/cast.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_fill_zero, api)
{
    std::vector<uint8_t> data(4, 0xFF);
    auto d = storage::storage(data);

    EXPECT_EQ(0xFFFFFFFFU, storage::cast<uint32_t>(d)[0]);

    storage::fill_zero(d);
    EXPECT_EQ(0x00000000U, storage::cast<uint32_t>(d)[0]);
}
