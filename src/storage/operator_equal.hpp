// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "is_equal.hpp"

namespace storage
{
/// @copydoc is_equal(const const_storage&, const const_storage&)
inline bool operator==(const const_storage& a, const const_storage& b)
{
    return is_equal(a, b);
}
}
