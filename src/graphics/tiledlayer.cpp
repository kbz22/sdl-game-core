#include "sgc/graphics/tiledlayer.hpp"

sgc::graphics::Tileset& sgc::graphics::TiledLayer::GetTileset() const
{
    return *m_tileset;
}

sgc::data::TileContainer& sgc::graphics::TiledLayer::GetTileContainer() const
{
    return *m_tileContainer;
}