#include "sgc/data/chunkedtilestorage.hpp"

std::optional<sgc::tile::TileId> sgc::data::ChunkedTileStorage::GetTileAt(GridCoord position) const
{
    sgc::data::ChunkCoord chunkPos;
    chunkPos.x = position.x / TileChunk::Size;
    chunkPos.y = position.y / TileChunk::Size;

    auto it = m_chunks.find(chunkPos);
    if (it == m_chunks.end()) {
        return std::nullopt;
    }

    const TileChunk& chunk = it->second;

    sgc::math::uval localX = position.x % TileChunk::Size;
    sgc::math::uval localY = position.y % TileChunk::Size;

    return chunk.tiles[localY * TileChunk::Size + localX];
}

void sgc::data::ChunkedTileStorage::SetTileAt(GridCoord position, sgc::tile::TileId tileId)
{
    sgc::data::ChunkCoord chunkPos;
    chunkPos.x = position.x / TileChunk::Size;
    chunkPos.y = position.y / TileChunk::Size;

    TileChunk& chunk = m_chunks[chunkPos]; // This will create a new chunk if it doesn't exist

    sgc::math::uval localX = position.x % TileChunk::Size;
    sgc::math::uval localY = position.y % TileChunk::Size;

    chunk.tiles[localY * TileChunk::Size + localX] = tileId;
}

void sgc::data::ChunkedTileStorage::SetChunkAt(ChunkCoord chunkPosition, sgc::tile::TileId tileId)
{
    TileChunk& chunk = m_chunks[chunkPosition]; // This will create a new chunk if it doesn't exist

    for (sgc::math::uval y = 0; y < TileChunk::Size; ++y) {
        for (sgc::math::uval x = 0; x < TileChunk::Size; ++x) {
            chunk.tiles[y * TileChunk::Size + x] = tileId;
        }
    }
}

void sgc::data::ChunkedTileStorage::SetChunkAt(ChunkCoord chunkPosition, const TileChunk& chunk)
{
    m_chunks[chunkPosition] = chunk;
}

void sgc::data::ChunkedTileStorage::RemoveChunkAt(ChunkCoord chunkPosition)
{
    m_chunks.erase(chunkPosition);
}