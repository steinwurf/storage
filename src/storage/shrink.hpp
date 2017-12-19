// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <cassert>

namespace storage
{
    template<class Storage>
    Storage shrink(const Storage& storage, uint32_t new_size)
    {
        assert(storage.size() >= new_size);
        return Storage(storage.data(), new_size);
    }
}
