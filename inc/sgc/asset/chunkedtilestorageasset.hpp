#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/tile/tile.hpp"
#include "sgc/data/tilechunk.hpp"

namespace sgc::data {
    struct TileChunk;
}

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