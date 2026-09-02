#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/data/serialization.hpp"

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::ChunkedTileStorageAsset>::Serialize(const sgc::asset::ChunkedTileStorageAsset &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(static_cast<sgc::asset::ChunkedTileStorageSize>(asset.chunks.size()));

    for (const auto &chunk : asset.chunks) {
        writer.Write(chunk.position.x);
        writer.Write(chunk.position.y);
        writer.Write(chunk.chunk.tiles);        
    }

    return writer.buffer;    
}