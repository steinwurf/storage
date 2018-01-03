// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/const_storage.hpp>
#include <storage/storage.hpp>

#include <gtest/gtest.h>

#include <string>
#include <cstdint>
#include <vector>

/// Test that we can convert a const std::string to storage::const_storage
/// object
TEST(test_const_storage, convert_const_string)
{
    const std::string str("test");
    storage::const_storage c = storage::storage(str);
    EXPECT_EQ(str.size(), c.size());
    EXPECT_EQ((uint8_t*) str.data(), c.data());
}
