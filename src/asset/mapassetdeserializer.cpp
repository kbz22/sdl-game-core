#include "sgc/asset/mapassetdeserializer.hpp"
#include "sgc/data/serialization.hpp"
#include <stdexcept>

sgc::asset::MapAsset sgc::asset::AssetDeserializer<sgc::asset::MapAsset>::Deserialize(const std::vector<uint8_t>& bytes)
{
    sgc::data::BinaryReader reader{
        bytes.data(),
        0
    };

    MapAsset mapAsset;

    mapAsset.tilesetId = reader.Read<sgc::data::AssetId>();
    auto layerCount = reader.Read<size_t>();

    mapAsset.layers.resize(layerCount);
    for(size_t i = 0; i < layerCount; ++i) {
        mapAsset.layers[i].name = reader.ReadString();

        uint8_t tileStorageType = reader.Read<uint8_t>();

        switch(tileStorageType) {
            case 0: // ChunkedTileStorageAsset
            {
                auto tileStorageSize = reader.Read<size_t>();
                std::vector<uint8_t> tileStorageBytes(
                    bytes.begin() + reader.offset,
                    bytes.begin() + reader.offset + tileStorageSize
                );
                mapAsset.layers[i].tileStorage = AssetDeserializer<ChunkedTileStorageAsset>::Deserialize(
                    tileStorageBytes
                );
                reader.offset += tileStorageSize;
                break;
            }
            default:
                throw std::runtime_error("Unknown tile storage type");
        }
        
    }

    return mapAsset;

}