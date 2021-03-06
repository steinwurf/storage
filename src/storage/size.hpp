// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

namespace storage
{
/// Returns the size of all the buffers in a storage sequence
/// @param first iterator to the first storage adapter
/// @param last iterator to the last storage adapter
/// @return the size in bytes of the storage adapters
template<class Iterator>
inline uint64_t size(Iterator first, Iterator last)
{
    uint64_t size = 0;
    while (first != last)
    {
        size += first->size();
        ++first;
    }
    return size;
}

template<class Storage>
inline uint64_t size(const Storage& storage)
{
    return size(storage.begin(), storage.end());
}
}
