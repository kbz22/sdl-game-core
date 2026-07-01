#include "sgc/data/statictilestorage.hpp"

sgc::data::StaticTileStorage::StaticTileStorage(GridCoord size) : m_size(size)
{
    m_tiles.resize(size.x * size.y, 0);
}

std::optional<sgc::tile::TileId> sgc::data::StaticTileStorage::GetTileAt(GridCoord position) const
{
    if (position.x >= m_size.x || position.y >= m_size.y) {
        return std::nullopt;
    }

    return m_tiles[position.y * m_size.x + position.x];
}

void sgc::data::StaticTileStorage::SetTileAt(GridCoord position, sgc::tile::TileId tileId) 
{
    if (position.x >= m_size.x || position.y >= m_size.y) {
        return;
    }

    m_tiles[position.y * m_size.x + position.x] = tileId;
}