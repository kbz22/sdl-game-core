#pragma once

#include "sgc/graphics/tileset.hpp"
#include "sgc/data/tilestorage.hpp"

namespace sgc::graphics {

    class TiledLayer {
        private:
            std::shared_ptr<Tileset> m_tileset;
            std::shared_ptr<data::TileContainer> m_tileContainer;

        public:
            TiledLayer(std::shared_ptr<Tileset> tileset, std::shared_ptr<data::TileContainer> tileContainer);

            Tileset& GetTileset() const;
            data::TileContainer& GetTileContainer() const;
            
    };

}