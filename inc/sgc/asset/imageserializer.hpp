#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/imageasset.hpp"

namespace sgc::asset{

    template<>
    class AssetSerializer<ImageAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(ImageAsset &asset);
    };

}