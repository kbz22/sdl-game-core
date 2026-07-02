#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/tilesetasset.hpp"

namespace sgc::asset {

    template<>
    class AssetSerializer<sgc::asset::TilesetAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(std::shared_ptr<sgc::asset::TilesetAsset> asset);
    };

}