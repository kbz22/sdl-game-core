#include "sgc/asset/chunkedtilestorageassetbuilder.hpp"
#include "sgc/data/chunkedtilestorage.hpp"

sgc::asset::ChunkedTileStorageAsset sgc::asset::AssetBuilder<sgc::asset::ChunkedTileStorageAsset>::Build(const sgc::data::ChunkedTileStorage &storage)
{
    ChunkedTileStorageAsset asset;

    for (const auto& [chunkCoord, chunk] : storage.m_chunks)
    {
        ChunkAsset chunkAsset;
        chunkAsset.position = chunkCoord;
        chunkAsset.chunk = chunk;

        asset.chunks.push_back(chunkAsset);
    }

    return asset;
}