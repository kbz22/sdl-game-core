#include "sgc/asset/assetheader.hpp"
#include "sgc/data/serialization.hpp"

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::data::AssetHeader>::Serialize(const AssetHeader &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(asset.id);
    writer.Write(asset.type);
    writer.Write(asset.size);

    return writer.buffer;
}