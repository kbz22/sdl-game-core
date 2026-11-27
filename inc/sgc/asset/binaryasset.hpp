#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include <vector>

namespace sgc::asset
{
    struct BinaryAsset
    {
        std::vector<uint8_t> data;
    };

    template<>
    struct AssetDeserializer<BinaryAsset>
    {
        static BinaryAsset Deserialize(const std::vector<uint8_t>& bytes);
    };

    template<>
    struct AssetSerializer<BinaryAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const BinaryAsset &asset);
    };
}