#include "sgc/asset/tilesetloader.hpp"
#include "sgc/data/resourcemanager.hpp"
#include "sgc/data/serialization.hpp"
#include "sgc/asset/tilesetasset.hpp"

std::shared_ptr<sgc::graphics::Tileset> sgc::asset::AssetLoader<sgc::graphics::Tileset>::Load(
    const std::vector<uint8_t>& data,
    sgc::data::ResourceContext& context,
    sgc::data::ResourceManager& rm
)
{
    sgc::data::BinaryReader reader{ data.data() };

    sgc::asset::TilesetAsset asset;
    asset.imageId = reader.Read<sgc::data::AssetId>();
    asset.tileSize.x = reader.Read<sgc::math::ival>();
    asset.tileSize.y = reader.Read<sgc::math::ival>();

    return std::make_shared<sgc::graphics::Tileset>(
        rm.LoadResource<sgc::graphics::Image>(asset.imageId, context),
        asset.tileSize
    );
}