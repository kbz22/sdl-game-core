#pragma once

#include "sgc/data/itilestorage.hpp"
#include "sgc/data/tilechunk.hpp"
#include "sgc/asset/chunkedtilestorageassetbuilder.hpp"
#include <optional>

namespace sgc::data {        

    class ChunkedTileStorage : public ITileStorage {
        private:
            std::unordered_map<ChunkCoord, TileChunk> m_chunks;

        public:

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const override;
            virtual void GetTilesWithin(GridCoord boundStart, GridCoord boundEnd, std::vector<tile::Tile>& tileBuffer) const override;

            virtual void SetTileAt(GridCoord position, std::optional<tile::TileId> tileId) override;

            void SetChunkAt(ChunkCoord chunkPosition, tile::TileId tileId);
            void SetChunkAt(ChunkCoord chunkPosition, const TileChunk& chunk);
            void RemoveChunkAt(ChunkCoord chunkPosition);

            friend struct sgc::asset::AssetBuilder<sgc::asset::ChunkedTileStorageAsset>;            
    };

}    