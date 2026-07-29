#include "sgc/asset/assetheaderdeserializer.hpp"
#include "sgc/data/resourcecontext.hpp"

std::shared_ptr<sgc::data::AssetHeader> sgc::asset::AssetDeserializer<sgc::data::AssetHeader>::Load(const std::vector<uint8_t> &data, sgc::data::ResourceContext& context)
{
    auto assetHeader = std::make_shared<sgc::data::AssetHeader>();

    std::memcpy(assetHeader.get(), data.data(), sizeof(sgc::data::AssetHeader));

    return assetHeader;
}