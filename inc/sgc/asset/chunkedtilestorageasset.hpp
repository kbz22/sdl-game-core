#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/data/chunkedtilestorage.hpp"

namespace sgc::asset {

    using ChunkedTileStorageSize = size_t;

    struct ChunkAsset {
        data::ChunkCoord position;
        data::TileChunk chunk;
    };

    struct ChunkedTileStorageAsset {
        std::vector<ChunkAsset> chunks;
    };

}