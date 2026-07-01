#pragma once

#include "sgc/data/itilestorage.hpp"
#include <optional>

namespace sgc::data {

    struct TileChunk {
        static constexpr sgc::math::u64 Size = 32;

        std::array<data::TileId, Size * Size> tiles;
    };

    class ChunkedTileStorage : public ITileStorage {
        private:
            std::unordered_map<ChunkCoord, TileChunk> m_chunks;

        public:
            virtual std::optional<data::TileId> GetTileAt(GridCoord position) const override;
            virtual void SetTileAt(GridCoord position, data::TileId tileId) override;

            void SetChunkAt(ChunkCoord chunkPosition, data::TileId tileId);
            void RemoveChunkAt(ChunkCoord chunkPosition);
            
    };

}    