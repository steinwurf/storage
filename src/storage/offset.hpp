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
    Storage offset(const Storage& storage, uint32_t offset)
    {
        assert(storage.size() > offset);
        return Storage(storage.data() + offset, storage.size() - offset);
    }
}
