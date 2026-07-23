#include "sgc/data/chunkedtilestorage.hpp"
#include "sgc/math/value.hpp"

std::optional<sgc::tile::TileId> sgc::data::ChunkedTileStorage::GetTileAt(GridCoord position) const
{
    ChunkCoord chunkPos;
    chunkPos.x = sgc::math::FloorDiv(position.x, TileChunk::Size);
    chunkPos.y = sgc::math::FloorDiv(position.y, TileChunk::Size);

    auto it = m_chunks.find(chunkPos);
    if (it == m_chunks.end()) {
        return std::nullopt;
    }

    const TileChunk& chunk = it->second;

    auto localX = sgc::math::FloorMod(position.x, TileChunk::Size);
    auto localY = sgc::math::FloorMod(position.y, TileChunk::Size);

    return chunk.tiles[localY * TileChunk::Size + localX];
}

void sgc::data::ChunkedTileStorage::SetTileAt(GridCoord position, std::optional<sgc::tile::TileId> tileId)
{
    ChunkCoord chunkPos;
    chunkPos.x = sgc::math::FloorDiv(position.x, TileChunk::Size);
    chunkPos.y = sgc::math::FloorDiv(position.y, TileChunk::Size);

    // setting a tile std::nullopt will remove entire chunk if it exists
    // this is to enable reverse operations on the tile storage, as setting a position
    // in an empty chunk to actual value creates that chunk in memory

    if (!tileId.has_value()) {
        RemoveChunkAt(chunkPos);
        return;
    }

    TileChunk& chunk = m_chunks[chunkPos];

    auto localX = sgc::math::FloorMod(position.x, TileChunk::Size);
    auto localY = sgc::math::FloorMod(position.y, TileChunk::Size);

    chunk.tiles[localY * TileChunk::Size + localX] = tileId.value();
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
    if (m_chunks.find(chunkPosition) != m_chunks.end()) {
        m_chunks.erase(chunkPosition);
    }
}