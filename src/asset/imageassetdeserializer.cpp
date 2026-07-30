#include "sgc/asset/imageassetdeserializer.hpp"

sgc::asset::ImageAsset sgc::asset::AssetDeserializer<sgc::asset::ImageAsset>::Deserialize(const std::vector<uint8_t> &data)
{
    static sgc::asset::ImageAsset imageAsset;

    std::memcpy(&imageAsset, data.data(), sizeof(sgc::asset::ImageAsset));

    return imageAsset;
}