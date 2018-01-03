// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "mutable_storage.hpp"
#include "const_storage.hpp"

#include <cassert>
#include <algorithm>

namespace storage
{
/// Copies the source storage into the destination storage buffer
/// @param dest The destination buffer
/// @param src The source buffer
inline void copy(const mutable_storage& dest, const const_storage& src)
{
    assert(dest.size() > 0);
    assert(dest.size() >= src.size());

    // Do not perform a copy if the two buffers are the same
    if (dest.data() == src.data()) return;

    std::copy(src.data(), src.data() + src.size(), dest.data());
}
}
