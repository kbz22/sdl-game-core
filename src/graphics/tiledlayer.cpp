#include "sgc/graphics/tiledlayer.hpp"

sgc::graphics::TiledLayer::TiledLayer(std::shared_ptr<Tileset> tileset, std::shared_ptr<data::ITileStorage> tileStorage) :
    m_tileset(tileset),
    m_tileStorage(tileStorage)
{}

sgc::graphics::Tileset& sgc::graphics::TiledLayer::GetTileset() const
{
    return *m_tileset;
}

sgc::data::ITileStorage& sgc::graphics::TiledLayer::GetTileStorage() const
{
    return *m_tileStorage;
}