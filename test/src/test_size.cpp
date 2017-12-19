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

TEST(test_size_container, api)
{
    uint32_t size = 500;
    std::vector<uint8_t> v(size);

    auto storage = storage::storage(v);

    EXPECT_EQ(size, storage::size(storage));
}

TEST(test_size_containers, api)
{
    std::vector<uint8_t> v1(12);
    std::vector<uint8_t> v2(45);

    auto storages = { storage::storage(v1), storage::storage(v2) };

    EXPECT_EQ(v1.size() + v2.size(), storage::size(storages));
}
