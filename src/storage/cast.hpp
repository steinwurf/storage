// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "mutable_storage.hpp"
#include "const_storage.hpp"

namespace storage
{
    /// Casts the stored pointer to a different data type
    /// @param s the storage adapter
    /// @return pointer to the requested storage data type
    template<class ValueType>
    inline ValueType* cast(const mutable_storage& s)
    {
        return reinterpret_cast<ValueType*>(s.m_data);
    }

    /// Casts the stored pointer to a different data type
    /// @param s the storage adapter
    /// @return pointer to the requested storage data type
    template<class ValueType>
    inline const ValueType* cast(const const_storage& s)
    {
        return reinterpret_cast<const ValueType*>(s.m_data);
    }
}
