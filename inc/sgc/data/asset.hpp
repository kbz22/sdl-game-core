#pragma once

#include <cstdint>

namespace sgc::data {

    using AssetId = uint64_t;

    enum class AssetType : uint32_t {

        Unknown = 0,

        Map,
        Tileset,
        Texture,

        Count
    };
    
}