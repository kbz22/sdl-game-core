#pragma once

#include "sgc/types.hpp"

#include <array>
#include <unordered_map>

namespace sgc::data {

    struct TileChunk {
        static constexpr sgc::math::u64 Size = 32;

        std::array<TileId, Size * Size> tiles;
    };

    class TileContainer {

        private:
            std::unordered_map<sgc::math::vec2, TileChunk> m_chunks;

        public:
            TileId GetTileAt(sgc::math::vec2 position) const;
            void SetTileAt(sgc::math::vec2 position, TileId tileId);

    };
}