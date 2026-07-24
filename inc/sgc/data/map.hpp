#pragma once

#include "sgc/data/layer.hpp"
#include "sgc/data/asset.hpp"
#include <memory>

namespace sgc::data {

    class Map 
    {
        private:
            std::vector<std::shared_ptr<Layer>> m_layers;
            sgc::data::AssetId m_tilesetId;

        public:
            Map(
                sgc::data::AssetId tilesetId,
                std::vector<std::shared_ptr<Layer>> layers
            );

            std::vector<std::shared_ptr<Layer>>& GetLayers();
            
            std::shared_ptr<Layer> GetLayer(size_t index) const;             
            size_t GetLayerCount() const;

            sgc::data::AssetId GetTilesetId() const;

    };

}