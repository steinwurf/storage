// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <cassert>

namespace storage
{
/// The mutable storage class contains a pointer
/// and size of a modifiable/mutable buffer
struct mutable_storage
{
    /// The value type used by the iterator
    using value_type = mutable_storage;

    /// The iterator type
    using const_iterator = const mutable_storage*;

    /// Create an initialized mutable storage object
    /// @param size the size of the buffer in bytes
    /// @param data pointer to the storage buffer
    mutable_storage(uint8_t* data, uint32_t size) :
        m_data(data),
        m_size(size)
    {
        assert(m_data != nullptr);
        assert(m_size != 0);
    }

    /// Create a mutable storage object from a mutable storage
    /// @param s the mutable storage object
    mutable_storage(const mutable_storage& s) :
        mutable_storage(s.m_data, s.m_size)
    { }

    /// Assigns and converts a mutable storage buffer
    /// into a mutable storage buffer
    /// @param s the mutable storage object
    mutable_storage& operator=(const mutable_storage& s)
    {
        m_data = s.m_data;
        m_size = s.m_size;
        return *this;
    }

    /// @return iterator to the first element note in this
    ///         adapter we always only have one element
    const_iterator begin() const
    {
        return this;
    }

    /// @return iterator to the end for this adapter we
    ///         always only have one element thus the + 1
    const_iterator end() const
    {
        return this + 1;
    }

    /// @return data pointer
    uint8_t* data() const
    {
        return m_data;
    }

    /// @return size
    uint32_t size() const
    {
        return m_size;
    }

private:

    /// Pointer to the mutable buffer storage
    uint8_t* m_data;

    /// The size of the mutable buffer
    uint32_t m_size;
};
}
