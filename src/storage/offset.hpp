// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <cassert>

namespace storage
{
/// Create a new storage object by offseting the given storage object.
///
/// Example of offsetting a storage by 3:
///
/// Given storage:     [0, 1, 2, 3, 4, 5]
/// Returned storage:  [3, 4, 5]
///
/// This function makes sure the bounds of the initial storage object is not
/// exceeded.
///
/// @param storage The storage object to be used for the offset operation
/// @param offset The number of bytes to offset the given storage object,
///               must be smaller than the storage object's size.
/// @return A new, offset storage object.
template<class Storage>
Storage offset(const Storage& storage, uint32_t offset)
{
    assert(storage.size() > offset);
    return Storage(storage.data() + offset, storage.size() - offset);
}
}
