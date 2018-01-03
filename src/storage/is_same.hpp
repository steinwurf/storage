// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

namespace storage
{
/// Compares two storage objects checks whether they refer to the
/// same storage i.e. whether data pointer and size are the same.
/// @param a The first storage object
/// @param b The second storage object
/// @return True if the two storage objects point to the same data
template<class Storage>
inline bool is_same(const Storage& a, const Storage& b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    // They have the same size - do they point to the same data?
    return a.data() == b.data();
}
}
