#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/tile/tile.hpp"
#include "sgc/data/tilechunk.hpp"
#include "sgc/asset/assetbuilder.hpp"
#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/runtimebuilder.hpp"

namespace sgc::data {
    struct TileChunk;
    class ChunkedTileStorage;
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

    template<>
    struct AssetBuilder<ChunkedTileStorageAsset, data::ChunkedTileStorage>
    {
        static ChunkedTileStorageAsset Build(const data::ChunkedTileStorage &storage);
    };

    template<>
    struct AssetSerializer<ChunkedTileStorageAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const ChunkedTileStorageAsset &asset);
    };

    template<>
    struct AssetDeserializer<sgc::asset::ChunkedTileStorageAsset>
    {
        static sgc::asset::ChunkedTileStorageAsset Deserialize(
            const std::vector<uint8_t>& data
        );
    };

    template<>
    struct RuntimeBuilder<sgc::data::ChunkedTileStorage>
    {
        static std::shared_ptr<sgc::data::ChunkedTileStorage> Build(const ChunkedTileStorageAsset& asset);
    };

}