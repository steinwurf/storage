// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

/// @file storage.hpp This implementation was inspired by the
/// boost::asio buffer.h as a way of providing an abstraction for
/// storage / buffers.

#pragma once

#include "mutable_storage.hpp"
#include "const_storage.hpp"

#include <cassert>
#include <algorithm>

namespace storage
{
    /// Copies the source storage into the destination storage buffer
    inline void copy(const mutable_storage& dest, const const_storage& src)
    {
        assert(dest.m_size > 0);
        assert(dest.m_size >= src.m_size);
        assert(dest.m_data != 0);
        assert(src.m_data != 0);

        // Do not perform a copy if the two buffers are the same
        if (dest.m_data == src.m_data) return;

        std::copy(src.m_data, src.m_data + src.m_size, dest.m_data);
    }
}
