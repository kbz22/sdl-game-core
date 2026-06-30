#pragma once 

#include "sgc/data/asset.hpp"
#include "sgc/types.hpp"

namespace sgc::asset {

    struct TilesetAsset
    {
        sgc::data::AssetId imageId;
        sgc::math::uvec2 tileSize;        
    };

}