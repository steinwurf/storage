// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "mutable_storage.hpp"

#include <cstdint>
#include <cassert>

namespace storage
{
/// The const storage class contains a pointer and
/// size of a non-modifiable/const buffer
struct const_storage
{
    /// The value type used by iterators
    using value_type = const_storage;

    /// The iterator type
    using const_iterator = const const_storage*;

    /// Create an initialized const storage object
    /// @param size the size of the buffer in bytes
    /// @param data pointer to the storage buffer
    const_storage(const uint8_t* data, uint64_t size) :
        m_data(data),
        m_size(size)
    {
        assert(data != nullptr);
        assert(size != 0);
    }

    /// Create a const storage object from a mutable storage
    /// @param s the mutable storage object
    const_storage(const mutable_storage& s) :
        const_storage(s.data(), s.size())
    { }

    /// Assigns and converts a mutable storage buffer
    /// into a const storage buffer
    /// @param s the mutable storage object
    const_storage& operator=(const mutable_storage& s)
    {
        m_data = s.data();
        m_size = s.size();
        return *this;
    }

    /// @return interator to the first element note in this
    ///         adapter we always only have one element
    const_iterator begin() const
    {
        return this;
    }

    /// @return interator to the end for this adapter we
    ///         always only have one element thus the + 1
    const_iterator end() const
    {
        return this + 1;
    }

    /// @return data pointer
    const uint8_t* data() const
    {
        return m_data;
    }

    /// @return size
    uint64_t size() const
    {
        return m_size;
    }

private:

    /// Pointer to the non-mutable buffer storage
    const uint8_t* m_data;

    /// The size of the non-mutable buffer
    uint64_t m_size;
};
}
