#pragma once

#include "sgc/data/itilestorage.hpp"
#include <optional>

namespace sgc::data {

    struct TileChunk {
        static constexpr sgc::math::u64 Size = 32;

        std::array<tile::TileId, Size * Size> tiles;
    };

    class ChunkedTileStorage : public ITileStorage {
        private:
            std::unordered_map<ChunkCoord, TileChunk> m_chunks;

        public:
            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const override;
            virtual void SetTileAt(GridCoord position, tile::TileId tileId) override;

            void SetChunkAt(ChunkCoord chunkPosition, tile::TileId tileId);
            void RemoveChunkAt(ChunkCoord chunkPosition);
            
    };

}    