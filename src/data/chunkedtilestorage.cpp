#include "sgc/data/chunkedtilestorage.hpp"

std::optional<sgc::tile::TileId> sgc::data::ChunkedTileStorage::GetTileAt(GridCoord position) const
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

void sgc::data::ChunkedTileStorage::SetTileAt(GridCoord position, sgc::tile::TileId tileId)
{
    sgc::math::uvec2 chunkPos;
    chunkPos.x = position.x / TileChunk::Size;
    chunkPos.y = position.y / TileChunk::Size;

    TileChunk& chunk = m_chunks[chunkPos]; // This will create a new chunk if it doesn't exist

    sgc::math::u64 localX = position.x % TileChunk::Size;
    sgc::math::u64 localY = position.y % TileChunk::Size;

    chunk.tiles[localY * TileChunk::Size + localX] = tileId;
}

void sgc::data::ChunkedTileStorage::SetChunkAt(ChunkCoord chunkPosition, sgc::tile::TileId tileId)
{
    TileChunk& chunk = m_chunks[chunkPosition]; // This will create a new chunk if it doesn't exist

    for (sgc::math::u64 y = 0; y < TileChunk::Size; ++y) {
        for (sgc::math::u64 x = 0; x < TileChunk::Size; ++x) {
            chunk.tiles[y * TileChunk::Size + x] = tileId;
        }
    }
}