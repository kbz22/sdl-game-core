#include "sgc/data/map.hpp"

sgc::data::Map::Map(
    sgc::data::AssetId tilesetId,
    std::vector<std::shared_ptr<Layer>> layers
) :
    m_tilesetId(tilesetId),
    m_layers(layers)
{}

std::vector<std::shared_ptr<sgc::data::Layer>>& sgc::data::Map::GetLayers() {
    return m_layers;
}

std::shared_ptr<sgc::data::Layer> sgc::data::Map::GetLayer(size_t index) const {
    if (index < m_layers.size()) {
        return m_layers[index];
    }
    return nullptr;
}

size_t sgc::data::Map::GetLayerCount() const {
    return m_layers.size();
}

sgc::data::AssetId sgc::data::Map::GetTilesetId() const {
    return m_tilesetId;
}