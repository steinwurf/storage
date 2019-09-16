// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <cassert>

namespace storage
{
/// Create a new storage object by shrinking the given storage object.
///
/// Example of shrinking a storage by 3:
///
/// Given storage:     [0, 1, 2, 3, 4, 5]
/// Returned storage:  [0, 1, 2]
///
/// This function makes sure the bounds of the initial storage object is not
/// exceeded.
///
/// @param storage The storage object to be used for the shrink operation
/// @param new_size The number of bytes to shrink the given storage object,
///               must be smaller than the storage object's size.
/// @return A new, shrunk storage object.
template<class Storage>
Storage shrink(const Storage& storage, uint64_t new_size)
{
    assert(new_size > 0);
    assert(new_size <= storage.size());
    return Storage(storage.data(), new_size);
}
}
