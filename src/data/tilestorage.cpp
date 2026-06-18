#include "sgc/data/tilestorage.hpp"

std::optional<sgc::data::TileId> sgc::data::TileContainer::GetTileAt(sgc::math::uvec2 position) const
{
    sgc::math::uvec2 chunkPos;
    chunkPos.x = position.x / TileChunk::Size;
    chunkPos.y = position.y / TileChunk::Size;

    auto it = m_chunks.find(chunkPos);
    if (it == m_chunks.end()) {
        return std::nullopt;
    }

    const TileChunk& chunk = it->second;

    sgc::math::u64 localX = position.x % TileChunk::Size;
    sgc::math::u64 localY = position.y % TileChunk::Size;

    return chunk.tiles[localY * TileChunk::Size + localX];
}

void sgc::data::TileContainer::SetTileAt(sgc::math::uvec2 position, TileId tileId)
{
    sgc::math::uvec2 chunkPos;
    chunkPos.x = position.x / TileChunk::Size;
    chunkPos.y = position.y / TileChunk::Size;

    TileChunk& chunk = m_chunks[chunkPos]; // This will create a new chunk if it doesn't exist

    sgc::math::u64 localX = position.x % TileChunk::Size;
    sgc::math::u64 localY = position.y % TileChunk::Size;

    chunk.tiles[localY * TileChunk::Size + localX] = tileId;
}