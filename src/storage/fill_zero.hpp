// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

/// @file storage.hpp This implementation was inspired by the
/// boost::asio buffer.h as a way of providing an abstraction for
/// storage / buffers.

#pragma once

#include "mutable_storage.hpp"

#include <algorithm>

namespace storage
{
    /// Zero the data buffer of a mutable storage object
    /// @param storage the mutable storage buffer
    inline void fill_zero(const mutable_storage& storage)
    {
        std::fill_n(storage.m_data, storage.m_size, 0);
    }
}
