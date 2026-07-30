#include "sgc/asset/assetheaderdeserializer.hpp"
#include "sgc/data/resourcecontext.hpp"

sgc::data::AssetHeader sgc::asset::AssetDeserializer<sgc::data::AssetHeader>::Deserialize(const std::vector<uint8_t> &data)
{
    static sgc::data::AssetHeader assetHeader;

    std::memcpy(&assetHeader, data.data(), sizeof(sgc::data::AssetHeader));

    return assetHeader;
}