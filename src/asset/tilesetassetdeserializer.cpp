#include "sgc/asset/tilesetassetdeserializer.hpp"

std::shared_ptr<sgc::asset::TilesetAsset> sgc::asset::AssetDeserializer<sgc::asset::TilesetAsset>::Load(const std::vector<uint8_t> &data, sgc::data::ResourceContext& context)
{
    auto tilesetAsset = std::make_shared<sgc::asset::TilesetAsset>();

    std::memcpy(tilesetAsset.get(), data.data(), sizeof(sgc::asset::TilesetAsset));

    return tilesetAsset;
}