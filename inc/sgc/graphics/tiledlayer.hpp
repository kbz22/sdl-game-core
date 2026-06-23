#pragma once

#include "sgc/graphics/tileset.hpp"
#include "sgc/data/itilestorage.hpp"

namespace sgc::graphics {

    class TiledLayer {
        private:
            std::shared_ptr<Tileset> m_tileset;
            std::shared_ptr<data::ITileStorage> m_tileStorage;

        public:
            TiledLayer(std::shared_ptr<Tileset> tileset, std::shared_ptr<data::ITileStorage> tileStorage);

            Tileset& GetTileset() const;
            data::ITileStorage& GetTileStorage() const;
            
    };

}