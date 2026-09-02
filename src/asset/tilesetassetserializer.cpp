#include "sgc/asset/tilesetasset.hpp"
#include "sgc/data/serialization.hpp"
#include <string>

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::TilesetAsset>::Serialize(const sgc::asset::TilesetAsset &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(asset.imageId);
    writer.Write(asset.tileSize.x);
    writer.Write(asset.tileSize.y);

    return writer.buffer;    
}

