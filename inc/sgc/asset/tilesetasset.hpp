#pragma once 

#include "sgc/data/asset.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"

namespace sgc::asset {

    struct TilesetAsset
    {
        sgc::data::AssetId imageId;
        sgc::tile::TileSize2D tileSize;
    };

}