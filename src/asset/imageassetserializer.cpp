#include "sgc/asset/imageserializer.hpp"

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::ImageAsset>::Serialize(const sgc::asset::ImageAsset &asset)
{   
    return asset.data;
}