// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <algorithm>

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
template<class Storage>
inline bool is_equal(const Storage& a, const Storage& b)
{
    // We cannot reuse is_same here since it does not tell use
    // which condition failed i.e. if is_same returns false. Then
    // we cannot just jump to a memory compare since it might be
    // because the two storage objects have different sizes.
    if (a.size() != b.size())
    {
        return false;
    }

    // They have the same size - do they point to the same data?
    if (a.data() == b.data())
    {
        return true;
    }

    // It is two different buffers - is the content equal?
    return std::equal(a.data(), a.data() + a.size(), b.data());
}
}
