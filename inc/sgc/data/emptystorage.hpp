#pragma once

#include "sgc/data/itilestorage.hpp"

namespace sgc::data {

    class EmptyStorage : public ITileStorage {
        public:
            EmptyStorage() = default;
            ~EmptyStorage() = default;

            std::optional<tile::TileId> GetTileAt(GridCoord position) const override {
                return std::nullopt;
            }

            void SetTileAt(GridCoord position, tile::TileId tileId) override {
                return;
            }
    };

}