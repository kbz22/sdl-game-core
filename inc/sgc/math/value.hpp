#pragma once

#include <cstdint>

namespace sgc::math {

    using ival = int64_t;
    using uval = uint64_t;

    constexpr ival FloorDiv(ival a, ival b)
    {
        if (a >= 0)
            return a / b;

        return -(((-a) + b - 1) / b);
    }

    constexpr ival FloorMod(ival a, ival b)
    {
        return a - FloorDiv(a, b) * b;
    }

    constexpr ival Abs(ival value)
    {
        return value < 0 ? -value : value;
    }

    constexpr ival AbsMod(ival value, ival mod)
    {
        return ((value % mod) + mod) % mod;
    }

    template<typename T>
    constexpr T Sign(T value)
    {
        return (T(0) < value) - (value < T(0));
    }

}