#include "sgc/asset/chunkedtilestorageloader.hpp"
#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/data/serialization.hpp"
#include <unordered_map>

std::shared_ptr<sgc::data::ChunkedTileStorage> sgc::asset::AssetLoader<sgc::data::ChunkedTileStorage>::Load(
    const std::vector<uint8_t>& data,
    sgc::data::ResourceContext& context,
    sgc::data::ResourceManager& rm
)
{
    sgc::data::BinaryReader reader{ data.data() };
    sgc::data::ChunkedTileStorage storage;    

    ChunkedTileStorageSize chunkCount = reader.Read<ChunkedTileStorageSize>();

    for (ChunkedTileStorageSize i = 0; i < chunkCount; ++i)
    {
        sgc::asset::ChunkAsset chunkAsset;
        chunkAsset.position = reader.Read<sgc::data::ChunkCoord>();
        chunkAsset.chunk = reader.Read<sgc::data::TileChunk>();
        
        storage.SetChunkAt(chunkAsset.position, chunkAsset.chunk);
    }

    return std::make_shared<sgc::data::ChunkedTileStorage>(std::move(storage));
}