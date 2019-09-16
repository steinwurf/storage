// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/cast.hpp>

#include <storage/storage.hpp>

#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

TEST(test_cast, api)
{
    std::vector<uint32_t> buffer = {1337, 110066};

    uint32_t* data = buffer.data();
    uint64_t size = buffer.size() * sizeof(uint32_t);

    auto storage = storage::storage(data, size);
    EXPECT_EQ(storage.size(), size);
    EXPECT_EQ(storage::cast<uint32_t>(storage), &data[0]);
}
