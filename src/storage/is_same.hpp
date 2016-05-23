// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

/// @file storage.hpp This implementation was inspired by the
/// boost::asio buffer.h as a way of providing an abstraction for
/// storage / buffers.

#pragma once

#include "const_storage.hpp"

namespace storage
{
    /// Compares two storage objects checks whether they refer to the
    /// same storage i.e. whether data pointer and size are the same.
    /// @param a The first storage object
    /// @param b The second storage object
    /// @return True if the two storage objects point to the same data
    inline bool is_same(const const_storage& a, const const_storage& b)
    {
        if (a.m_size != b.m_size)
        {
            return false;
        }

        // They have the same size - do they point to the same data?
        return a.m_data == b.m_data;
    }
}
