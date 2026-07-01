#pragma once

#include "sgc/data/asset.hpp"

namespace sgc::asset {

    struct ChunkedTileStorageAsset
    {
        sgc::data::AssetId tilesetId;
        sgc::math::uvec2 chunkSize;
    };

}