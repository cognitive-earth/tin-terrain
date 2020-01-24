#pragma once

#include <algorithm>

#define TNTN_LITTLE_ENDIAN

namespace tntn {

enum class Endianness
{
    BIG,
    LITTLE,
};

constexpr Endianness PLATFORM_NATIVE_ENDIANNESS = Endianness::LITTLE;

inline void flip_endianness_4byte(unsigned char* data)
{
    std::swap(data[0], data[3]);
    std::swap(data[1], data[2]);
}

} // namespace tntn
