#include "sgc/asset/tilesetasset.hpp"

sgc::asset::TilesetAsset sgc::asset::AssetDeserializer<sgc::asset::TilesetAsset>::Deserialize(const std::vector<uint8_t> &data)
{
    static sgc::asset::TilesetAsset tilesetAsset;

    std::memcpy(&tilesetAsset, data.data(), sizeof(sgc::asset::TilesetAsset));

    return tilesetAsset;
}