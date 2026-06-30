#pragma once

#include <cstdint>
#include <string>

namespace sgc::data {

    using AssetId = uint64_t;

    enum class AssetType : uint32_t {

        Unknown = 0,

        Map,
        Tileset,
        Texture,

        Count
    };        

    inline AssetId HashAsset(const std::string& str)
    {
        uint64_t hash = 14695981039346656037ull; // FNV offset basis

        for (char c : str)
        {
            hash ^= static_cast<uint64_t>(c);
            hash *= 1099511628211ull;
        }

        return hash;
    }
    
}