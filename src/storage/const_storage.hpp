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
        typedef const_storage value_type;

        /// The iterator type
        typedef const const_storage* const_iterator;

        /// Create an empty storage object
        const_storage() :
            m_data(0),
            m_size(0)
        { }

        /// Create an initialized const storage object
        /// @param size the size of the buffer in bytes
        /// @param data pointer to the storage buffer
        const_storage(const uint8_t* data, uint32_t size) :
            m_data(data),
            m_size(size)
        { }

        /// Create a const storage object from a mutable storage
        /// @param s the mutable storage object
        const_storage(const mutable_storage& s) :
            m_data(s.m_data),
            m_size(s.m_size)
        { }

        /// Assigns and converts a mutable storage buffer
        /// into a const storage buffer
        /// @param s the mutable storage object
        const_storage& operator=(const mutable_storage& s)
        {
            m_data = s.m_data;
            m_size = s.m_size;
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

        /// Offset the storage
        const_storage& operator+=(uint32_t offset)
        {
            assert(offset <= m_size);
            m_size -= offset;
            m_data += offset;
            return *this;
        }

        /// Offset the storage
        const_storage operator+(uint32_t offset)
        {
            assert(offset <= m_size);
            const_storage storage(m_data + offset, m_size - offset);

            return storage;
        }

        /// Pointer to the non-mutable buffer storage
        const uint8_t* m_data;

        /// The size of the mutable buffer
        uint32_t m_size;
    };
}
