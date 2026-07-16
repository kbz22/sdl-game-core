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

}