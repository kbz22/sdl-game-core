#include "sgc/data/statictilestorage.hpp"

sgc::data::StaticTileStorage::StaticTileStorage(GridSize size) : m_size(size)
{
    m_tiles.resize(size.x * size.y, 0);
}

std::optional<sgc::tile::TileId> sgc::data::StaticTileStorage::GetTileAt(GridCoord position) const
{
    auto sizeX = static_cast<sgc::math::ival>(m_size.x);
    auto sizeY = static_cast<sgc::math::ival>(m_size.y);

    if (position.x >= sizeX || position.y >= sizeY) {
        return std::nullopt;
    }

    return m_tiles[position.y * sizeX + position.x];
}

void sgc::data::StaticTileStorage::SetTileAt(GridCoord position, std::optional<sgc::tile::TileId> tileId)
{
    if (!tileId.has_value()) {
        //! If tileId is std::nullopt, we can choose to either do nothing or remove the tile.
        // For this implementation, we'll do nothing.
        return;
    }

    auto sizeX = static_cast<sgc::math::ival>(m_size.x);
    auto sizeY = static_cast<sgc::math::ival>(m_size.y);

    if (position.x >= sizeX || position.y >= sizeY) {
        return;
    }

    m_tiles[position.y * sizeX + position.x] = tileId.value();
}