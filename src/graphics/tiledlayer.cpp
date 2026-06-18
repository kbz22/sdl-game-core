#include "sgc/graphics/tiledlayer.hpp"

sgc::graphics::TiledLayer::TiledLayer(std::shared_ptr<Tileset> tileset, std::shared_ptr<data::TileContainer> tileContainer) :
    m_tileset(tileset),
    m_tileContainer(tileContainer)
{}

sgc::graphics::Tileset& sgc::graphics::TiledLayer::GetTileset() const
{
    return *m_tileset;
}

sgc::data::TileContainer& sgc::graphics::TiledLayer::GetTileContainer() const
{
    return *m_tileContainer;
}