// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "mutable_storage.hpp"

#include <algorithm>

namespace storage
{
/// Zero the data buffer of a mutable storage object
/// @param storage the mutable storage buffer
inline void fill_zero(const mutable_storage& storage)
{
    std::fill_n(storage.data(), storage.size(), 0);
}
}
