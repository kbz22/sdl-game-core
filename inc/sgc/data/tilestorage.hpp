#pragma once

#include "sgc/types.hpp"

#include <array>
#include <optional>
#include <unordered_map>

namespace sgc::data {

    using ChunkCoord = sgc::math::uvec2;
    using GridCoord = sgc::math::uvec2;
    using TileId = uint32_t;

    struct TileChunk {
        static constexpr sgc::math::u64 Size = 32;

        std::array<TileId, Size * Size> tiles;
    };

    class TileContainer {

        private:
            std::unordered_map<ChunkCoord, TileChunk> m_chunks;

        public:
            std::optional<TileId> GetTileAt(GridCoord position) const;
            void SetTileAt(GridCoord position, TileId tileId);

            const TileChunk* GetChunk(ChunkCoord coord) const;

    };
}