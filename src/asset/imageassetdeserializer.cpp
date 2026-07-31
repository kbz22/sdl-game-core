#include "sgc/asset/imageassetdeserializer.hpp"

sgc::asset::ImageAsset sgc::asset::AssetDeserializer<sgc::asset::ImageAsset>::Deserialize(const std::vector<uint8_t> &data)
{
    sgc::asset::ImageAsset imageAsset;

    imageAsset.data = data;

    return imageAsset;
}