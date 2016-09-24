// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

namespace storage
{
/// Splits a continuous storage buffer into a sequence of
/// storage buffers where the original buffer is split at
/// a specified number of bytes
/// @param storage The storage to split
/// @param split The number of bytes to split the storage in.
template<class StorageType>
std::vector<StorageType> split(const StorageType& storage, uint32_t split)
{
    auto remaining_size = storage.m_size;
    auto data_offset = storage.m_data;

    std::vector<StorageType> sequence;

    while (remaining_size > 0)
    {
        uint32_t next_size = std::min(remaining_size, split);

        sequence.push_back(StorageType(data_offset, next_size));

        data_offset += next_size;
        remaining_size -= next_size;
    }

    return sequence;
}
}
