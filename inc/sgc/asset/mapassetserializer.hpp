#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/mapasset.hpp"

namespace sgc::asset {

    template<>
    struct AssetSerializer<MapAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const MapAsset &asset);
    };

}