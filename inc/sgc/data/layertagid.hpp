#pragma once

#include <cstdint>

namespace sgc::data {

    struct LayerTagId {
        uint32_t value;
        
        auto operator<=>(const LayerTagId&) const = default;
    };

}