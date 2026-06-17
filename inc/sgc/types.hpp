#pragma once

#include <cstdint>

namespace sgc::math {

    using i64 = int64_t;
    using u64 = uint64_t;

    struct vec2 {
        i64 x;
        i64 y;
    };

    struct uvec2 {
        u64 x;
        u64 y;
    };

}

namespace sgc::graphics {

    struct color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
    
}