#pragma once

#include <vector>
#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/assetdeserializer.hpp"

namespace sgc::asset {

    // This is basically a wrapper for a PNG
    struct ImageAsset
    {
        std::vector<uint8_t> data;
    };

    template<>
    struct AssetSerializer<ImageAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const ImageAsset &asset);
    };

    template<>
    struct AssetDeserializer<ImageAsset>
    {
        public:
            static ImageAsset Deserialize(
                const std::vector<uint8_t> &data
            );
    };

}