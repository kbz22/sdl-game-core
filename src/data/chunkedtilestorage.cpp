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
    if (!tileId.has_value()) {
        //! If tileId is std::nullopt, we can choose to either do nothing or remove the tile.
        // For this implementation, we'll do nothing.
        return;
    }

    ChunkCoord chunkPos;
    chunkPos.x = sgc::math::FloorDiv(position.x, TileChunk::Size);
    chunkPos.y = sgc::math::FloorDiv(position.y, TileChunk::Size);

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
    m_chunks.erase(chunkPosition);
}