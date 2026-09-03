#include "sgc/asset/mapasset.hpp"
#include "sgc/data/serialization.hpp"
#include <stdexcept>
#include <memory>

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::MapAsset>::Serialize(const MapAsset &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(asset.tilesetId);
    writer.Write(asset.layers.size());

    for(const auto &layer : asset.layers) {
        writer.WriteString(layer.name);
        writer.Write(layer.tags.size());

        for(const auto &tagId : layer.tags) {
            writer.Write(tagId);
        }

        if(std::holds_alternative<ChunkedTileStorageAsset>(layer.tileStorage)) {
            auto &chunkedStorage = std::get<ChunkedTileStorageAsset>(layer.tileStorage);
            auto chunkedStorageBytes = sgc::asset::AssetSerializer<ChunkedTileStorageAsset>::Serialize(
                chunkedStorage
            );
            writer.Write(static_cast<uint8_t>(0));
            writer.Write(chunkedStorageBytes.size());
            writer.buffer.insert(
                writer.buffer.end(),
                chunkedStorageBytes.begin(),
                chunkedStorageBytes.end()
            );
        } else {
            throw std::runtime_error("Unknown tile storage type");
        }        
    }    

    return std::move(writer.buffer);
}