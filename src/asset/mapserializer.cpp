#include "sgc/asset/mapserializer.hpp"
#include "sgc/data/serialization.hpp"

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::MapAsset>::Serialize(const MapAsset &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(asset.tilesetId);
    writer.Write(static_cast<size_t>(asset.layers.size()));

    for (const auto &layer : asset.layers) {
        writer.Write(layer.name);
        writer.Write(layer.storageId);
        writer.Write(static_cast<size_t>(layer.tags.size()));
        for (const auto &tag : layer.tags) {
            writer.Write(tag);
        }
    }

    return writer.buffer;
}