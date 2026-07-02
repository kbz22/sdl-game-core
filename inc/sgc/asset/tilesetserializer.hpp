#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/tilesetasset.hpp"

namespace sgc::asset {

    template<>
    class AssetSerializer<TilesetAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(TilesetAsset &asset);
    };

}