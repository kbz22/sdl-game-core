#pragma once 

#include "sgc/data/asset.hpp"
#include "sgc/math/vector.hpp"

namespace sgc::asset {

    struct TilesetAsset
    {
        sgc::data::AssetId imageId;
        sgc::math::uvec2 tileSize;        
    };

}