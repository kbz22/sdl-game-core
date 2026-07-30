#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/tilesetasset.hpp"

namespace sgc::asset {

    template<>
    struct AssetDeserializer<TilesetAsset>
    {
        public:
            static TilesetAsset Deserialize(
                const std::vector<uint8_t> &data
            );
    };

}