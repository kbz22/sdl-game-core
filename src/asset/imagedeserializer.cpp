#include "sgc/asset/imagedeserializer.hpp"

std::shared_ptr<sgc::graphics::Image> sgc::asset::AssetDeserializer<sgc::graphics::Image>::Load(
    const std::vector<uint8_t>& data,
    sgc::data::ResourceContext& context,
    sgc::data::ResourceManager& rm
)
{
    auto img = std::make_shared<sgc::graphics::Image>();

    img->LoadTexture(
        context.renderer,
        data
    );

    return img;
};