#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/mapasset.hpp"

namespace sgc::asset {

    template<>
    class AssetDeserializer<MapAsset>
    {
        public:
            static MapAsset Deserialize(const std::vector<uint8_t>& bytes);
    };

}