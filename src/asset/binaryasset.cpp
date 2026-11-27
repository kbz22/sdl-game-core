#include "sgc/asset/binaryasset.hpp"
#include <stdexcept>

using sgc::asset::BinaryAsset, sgc::asset::AssetSerializer, sgc::asset::AssetDeserializer;

BinaryAsset AssetDeserializer<BinaryAsset>::Deserialize(const std::vector<uint8_t>& bytes)
{
    return {bytes};
}

std::vector<uint8_t> AssetSerializer<BinaryAsset>::Serialize(const BinaryAsset &asset)
{
    return asset.data;
}