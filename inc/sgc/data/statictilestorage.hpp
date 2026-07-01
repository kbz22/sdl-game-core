#pragma once

#include "sgc/data/itilestorage.hpp"
#include <vector>

namespace sgc::data {

    class StaticTileStorage : public ITileStorage {

        private:
            std::vector<tile::TileId> m_tiles;
            GridCoord m_size;

        public:
            StaticTileStorage(GridCoord size);

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const override;
            virtual void SetTileAt(GridCoord position, tile::TileId tileId) override;
        
    };

}