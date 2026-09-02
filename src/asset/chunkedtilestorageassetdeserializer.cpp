#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/data/chunkedtilestorage.hpp"
#include "sgc/data/serialization.hpp"
#include <unordered_map>

sgc::asset::ChunkedTileStorageAsset sgc::asset::AssetDeserializer<sgc::asset::ChunkedTileStorageAsset>::Deserialize(
    const std::vector<uint8_t>& data
)
{
    sgc::data::BinaryReader reader{ data.data() };    
    sgc::asset::ChunkedTileStorageAsset asset;

    ChunkedTileStorageSize chunkCount = reader.Read<ChunkedTileStorageSize>();

    for (ChunkedTileStorageSize i = 0; i < chunkCount; ++i)
    {
        sgc::asset::ChunkAsset chunkAsset;
        chunkAsset.position = reader.Read<sgc::data::ChunkCoord>();
        chunkAsset.chunk = reader.Read<sgc::data::TileChunk>();
        
        asset.chunks.push_back(chunkAsset);
    }    

    return asset;
}