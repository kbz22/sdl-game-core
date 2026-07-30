#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/tilesetasset.hpp"

namespace sgc::asset {

    template<>
    struct AssetSerializer<TilesetAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const TilesetAsset &asset);
    };

}