#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/data/resourcecontext.hpp"

#include <memory>

namespace sgc::data {
    class ResourceManager;
}

namespace sgc::asset {

    template<typename T>
    struct AssetLoader;

    template<>
    struct AssetLoader<sgc::graphics::Image>
    {
        static std::shared_ptr<sgc::graphics::Image> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context,
            sgc::data::ResourceManager& /*rm*/
        )
        {
            auto img = std::make_shared<sgc::graphics::Image>();

            img->LoadTexture(
                context.renderer,
                data);

            return img;
        }
    };

}