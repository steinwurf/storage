// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>

namespace storage
{
/// Returns the size of all the buffers in a storage sequence
/// @param first iterator to the first storage adapter
/// @param last iterator to the last storage adapter
/// @return the size in bytes of the storage adapters
template<class Iterator>
inline uint32_t size(Iterator first, Iterator last)
{
    uint32_t size = 0;
    while (first != last)
    {
        size += first->m_size;
        ++first;
    }
    return size;
}
}
