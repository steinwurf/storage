// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "offset.hpp"
#include "shrink.hpp"

#include <cstdint>
#include <cassert>

namespace storage
{
/// Create a new storage object by slicing the given storage object.
///
/// Example of slicing a storage with offset 3 and size 2:
///
/// Given storage:     [0, 1, 2, 3, 4, 5]
/// Returned storage:  [3, 4]
///
/// This function makes sure the bounds of the initial storage object is not
/// exceeded.
///
/// @param storage The storage object to be used for the slice operation
/// @param offset The number of bytes to offset the given storage object,
///               must be smaller than the storage object's size.
/// @param size The number of bytes to include in the slice,
///               must be smaller than the offset storage object's size.
/// @return A new, sliced storage object.
template<class Storage>
Storage slice(const Storage& storage, uint64_t offset, uint64_t size)
{
    assert(size > 0);
    assert(offset < storage.size());
    assert(size <= storage.size() - offset);
    auto tmp = storage::offset(storage, offset);
    return shrink(tmp, size);
}
}
