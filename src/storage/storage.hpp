// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "const_storage.hpp"
#include "mutable_storage.hpp"

#include "cast.hpp"
#include "copy.hpp"
#include "fill_zero.hpp"
#include "is_equal.hpp"
#include "is_same.hpp"
#include "offset.hpp"
#include "operator_equal.hpp"
#include "shrink.hpp"
#include "size.hpp"
#include "slice.hpp"
#include "split.hpp"

#include <cstdint>
#include <string>
#include <vector>
#include <array>

namespace storage
{
/// Storage function for pointers to mutable data
/// @param data pointer to the data buffer
/// @param size_in_bytes the size of data buffer in bytes
/// @return the storage adapter
inline mutable_storage storage(void* data, uint64_t size_in_bytes)
{
    uint8_t* data_ptr = reinterpret_cast<uint8_t*>(data);
    return mutable_storage(data_ptr, size_in_bytes);
}

/// Storage function for pointers to const data
/// @param data pointer to the data buffer
/// @param size_in_bytes the size of data buffer in bytes
/// @return the storage adapter
inline const_storage storage(const void* data, uint64_t size_in_bytes)
{
    const uint8_t* data_ptr = reinterpret_cast<const uint8_t*>(data);
    return const_storage(data_ptr, size_in_bytes);
}

/// Creates a mutable storage object
/// @param v is a std::vector buffer
/// @return the storage adapter
template<class PodType, class Allocator>
inline mutable_storage storage(std::vector<PodType, Allocator>& v)
{
    uint64_t size = static_cast<uint64_t>(v.size() * sizeof(PodType));
    uint8_t* data = reinterpret_cast<uint8_t*>(v.data());

    return mutable_storage(data, size);
}

/// Creates a const storage object
/// @param v is a std::vector buffer
/// @return the storage adapter
template<class PodType, class Allocator>
inline const_storage storage(const std::vector<PodType, Allocator>& v)
{
    uint64_t size = static_cast<uint64_t>(v.size() * sizeof(PodType));
    const uint8_t* data = reinterpret_cast<const uint8_t*>(v.data());

    return const_storage(data, size);
}

/// We do not allow conversion of temporaries
template<class PodType, class Allocator>
const_storage storage(std::vector<PodType, Allocator>&&) = delete;

/// Creates a mutable storage object from a string
/// @param str is a std::string
/// @return the storage adapter
inline mutable_storage storage(std::string& str)
{
    uint64_t size = static_cast<uint64_t>(str.size());
    uint8_t* data = reinterpret_cast<uint8_t*>(&str[0]);

    return mutable_storage(data, size);
}

/// Creates a const storage object from a const string
/// @param str is a const std::string
/// @return the storage adapter
inline const_storage storage(const std::string& str)
{
    uint64_t size = static_cast<uint64_t>(str.size());
    const uint8_t* data = reinterpret_cast<const uint8_t*>(str.data());

    return const_storage(data, size);
}

/// We do not allow conversion of temporaries
const_storage storage(std::string&&) = delete;

/// Creates a mutable storage object
/// @param a is a std::array buffer
/// @return the storage adapter
template<class PodType, std::size_t Size>
inline mutable_storage storage(std::array<PodType, Size>& a)
{
    uint64_t size = static_cast<uint64_t>(Size * sizeof(PodType));
    uint8_t* data = reinterpret_cast<uint8_t*>(a.data());

    return mutable_storage(data, size);
}

/// Creates a const storage object
/// @param a is a std::array buffer
/// @return the storage adapter
template<class PodType, std::size_t Size>
inline const_storage storage(const std::array<PodType, Size>& a)
{
    uint64_t size = static_cast<uint64_t>(Size * sizeof(PodType));
    const uint8_t* data = reinterpret_cast<const uint8_t*>(a.data());

    return const_storage(data, size);
}

/// We do not allow conversion of temporaries
template<class PodType, std::size_t Size>
const_storage storage(std::array<PodType, Size>&&) = delete;
}
