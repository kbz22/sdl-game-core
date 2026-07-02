#include "sgc/asset/tilesetserializer.hpp"
#include "sgc/data/serialization.hpp"
#include <string>

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::TilesetAsset>::Serialize(std::shared_ptr<sgc::asset::TilesetAsset> asset)
{
    if (!asset) {
        return {};
    }

    sgc::data::BinaryWriter writer{};

    writer.Write(asset->imageId);
    writer.Write(asset->tileSize.x);
    writer.Write(asset->tileSize.y);

    return writer.buffer;    
}

