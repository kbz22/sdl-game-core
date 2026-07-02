#include "sgc/asset/imageserializer.hpp"

std::vector<uint8_t> sgc::asset::AssetSerializer<sgc::asset::ImageAsset>::Save(std::shared_ptr<sgc::asset::ImageAsset> asset)
{
    std::vector<uint8_t> data;

    if (!asset) {
        return data;
    }

    data = asset->data;    
    
    return data;
}