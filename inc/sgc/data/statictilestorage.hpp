#pragma once

#include "sgc/data/itilestorage.hpp"
#include <vector>

namespace sgc::data {

    class StaticTileStorage : public ITileStorage {

        private:
            std::vector<tile::TileId> m_tiles;
            GridSize m_size;

        public:
            StaticTileStorage(GridSize size);

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const override;
            virtual void GetTilesWithin(GridCoord boundStart, GridCoord boundEnd, std::vector<tile::Tile>& tileBuffer) const override;
            
            virtual void SetTileAt(GridCoord position, std::optional<tile::TileId> tileId) override;
        
    };

}