#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/imageasset.hpp"

namespace sgc::asset {

    template<>
    struct AssetDeserializer<ImageAsset>
    {
        public:
            static ImageAsset Deserialize(
                const std::vector<uint8_t> &data
            );
    };

}