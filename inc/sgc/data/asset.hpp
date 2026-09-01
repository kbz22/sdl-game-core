#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace sgc::data {

    using AssetId = uint64_t;

    enum class AssetType : uint32_t {

        Unknown = 0,

        Map,
        Tileset,
        Texture,

        External,

        Count
    };
    
    struct AssetHeader {
        AssetId id;
        AssetType type;
        size_t size;
    };

    // Used for serializing and deserializing asset headers
    constexpr size_t PackedAssetHeaderSize =
        sizeof(data::AssetId) +
        sizeof(data::AssetType) +
        sizeof(size_t);
    
    struct BinaryAsset {
        AssetHeader header;
        std::vector<uint8_t> data;
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

    inline AssetId HashAsset(const std::wstring& str)
    {
        uint64_t hash = 14695981039346656037ull; // FNV offset basis

        for (wchar_t c : str)
        {
            hash ^= static_cast<uint64_t>(c);
            hash *= 1099511628211ull;
        }

        return hash;
    }
    
}