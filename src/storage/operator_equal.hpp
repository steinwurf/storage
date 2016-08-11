// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "is_equal.hpp"

namespace storage
{
    /// Compares two storage objects to see whether they are
    /// equal. The condition for two storage objects are bit wider
    /// than for is_same. Two storage objects are equal either if the
    /// point to exactly the same storage or if they contain exactly
    /// the same data.
    ///
    /// @param a The first storage object
    /// @param b The second storage object
    /// @return True if the storage objects contain the same data
    ///         otherwise false.
    inline bool operator==(const const_storage& a, const const_storage& b)
    {
        return is_equal(a, b);
    }
}
