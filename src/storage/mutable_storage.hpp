// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

/// @file storage.hpp This implementation was inspired by the
/// boost::asio buffer.h as a way of providing an abstraction for
/// storage / buffers.

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
        typedef mutable_storage value_type;

        /// The iterator type
        typedef const mutable_storage* const_iterator;

        /// Create an empty storage object
        mutable_storage() :
            m_data(0),
            m_size(0)
        { }

        /// Create an initialized mutable storage object
        /// @param size the size of the buffer in bytes
        /// @param data pointer to the storage buffer
        mutable_storage(uint8_t* data, uint32_t size) :
            m_data(data),
            m_size(size)
        {
            assert(m_data != 0);
            assert(m_size > 0);
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

        /// Offset the storage
        mutable_storage& operator+=(uint32_t offset)
        {
            assert(offset <= m_size);
            m_size -= offset;
            m_data += offset;
            return *this;
        }

        /// Offset the storage
        mutable_storage operator+(uint32_t offset)
        {
            assert(offset <= m_size);
            mutable_storage storage(m_data + offset, m_size - offset);

            return storage;
        }

        /// Pointer to the mutable buffer storage
        uint8_t* m_data;

        /// The size of the mutable buffer
        uint32_t m_size;
    };
}
