#include "sgc/asset/imageassetdeserializer.hpp"

std::shared_ptr<sgc::asset::ImageAsset> sgc::asset::AssetDeserializer<sgc::asset::ImageAsset>::Load(const std::vector<uint8_t> &data, sgc::data::ResourceContext& context)
{
    auto imageAsset = std::make_shared<sgc::asset::ImageAsset>();

    std::memcpy(imageAsset.get(), data.data(), sizeof(sgc::asset::ImageAsset));

    return imageAsset;
}