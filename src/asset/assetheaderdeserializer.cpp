#include "sgc/asset/assetheaderdeserializer.hpp"
#include "sgc/data/resourcecontext.hpp"
#include "sgc/data/serialization.hpp"

sgc::data::AssetHeader sgc::asset::AssetDeserializer<sgc::data::AssetHeader>::Deserialize(const std::vector<uint8_t> &data)
{
    BinaryReader reader{
        data.data(),
        0
    };

    sgc::data::AssetHeader assetHeader;
    assetHeader.id = reader.Read<sgc::data::AssetId>();
    assetHeader.type = reader.Read<sgc::data::AssetType>();
    assetHeader.size = reader.Read<size_t>();

    return assetHeader;
}