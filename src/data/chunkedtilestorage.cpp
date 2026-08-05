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

void sgc::data::ChunkedTileStorage::GetTilesWithin(GridCoord boundStart, GridCoord boundEnd, std::vector<sgc::tile::Tile>& tileBuffer) const
{
    using namespace sgc::math;

    ChunkCoord chunkPos{
        FloorDiv(boundStart.x, TileChunk::Size),
        FloorDiv(boundStart.y, TileChunk::Size)
    };

    ChunkCoord chunkEndPos{
        FloorDiv(boundEnd.x - 1, TileChunk::Size),
        FloorDiv(boundEnd.y - 1, TileChunk::Size)
    };

    for (ival chunkY = chunkPos.y; chunkY <= chunkEndPos.y; ++chunkY) {
        for(ival chunkX = chunkPos.x; chunkX <= chunkEndPos.x; ++chunkX) 
        {
            auto chunkIt = m_chunks.find({chunkX, chunkY});
            if (chunkIt != m_chunks.end()) {
                const TileChunk& chunk = chunkIt->second;
                tileBuffer.reserve(tileBuffer.size() + (TileChunk::Size * TileChunk::Size));

                ival startX = std::max(boundStart.x, chunkX * TileChunk::Size);
                ival endX = std::min(boundEnd.x, (chunkX + 1) * TileChunk::Size);

                ival startY = std::max(boundStart.y, chunkY * TileChunk::Size);
                ival endY = std::min(boundEnd.y, (chunkY + 1) * TileChunk::Size);

                for (ival y = startY; y < endY; ++y) {
                    for (ival x = startX; x < endX; ++x) {
                        auto localX = FloorMod(x, TileChunk::Size);
                        auto localY = FloorMod(y, TileChunk::Size);
                        tileBuffer.push_back({{x, y}, chunk.tiles[localY * TileChunk::Size + localX]});
                    }
                }
            }
        }
    }    
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

std::optional<sgc::data::TileChunk> sgc::data::ChunkedTileStorage::RemoveChunkAt(ChunkCoord chunkPosition)
{
    auto it = m_chunks.find(chunkPosition);
    if (it != m_chunks.end()) {
        TileChunk chunk = it->second; // copy
        m_chunks.erase(it);        
        return chunk;
    }   

    return std::nullopt;
}

sgc::data::ChunkCoord sgc::data::ChunkedTileStorage::GetChunkCoordAt(GridCoord position)
{
    ChunkCoord chunkPos;
    chunkPos.x = sgc::math::FloorDiv(position.x, TileChunk::Size);
    chunkPos.y = sgc::math::FloorDiv(position.y, TileChunk::Size);
    return chunkPos;
}