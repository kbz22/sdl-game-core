#pragma once 

#include "sgc/data/asset.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"
#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/assetdeserializer.hpp"

namespace sgc::asset {

    struct TilesetAsset
    {
        sgc::data::AssetId imageId;
        sgc::tile::TileSize2D tileSize;
    };

    template<>
    struct AssetSerializer<TilesetAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const TilesetAsset &asset);
    };

    template<>
    struct AssetDeserializer<TilesetAsset>
    {
        public:
            static TilesetAsset Deserialize(
                const std::vector<uint8_t> &data
            );
    };


}