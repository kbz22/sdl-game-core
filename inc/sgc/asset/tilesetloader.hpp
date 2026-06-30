#pragma once

#include "sgc/graphics/tileset.hpp"
#include "sgc/asset/assetloader.hpp"

namespace sgc::data
{
    class ResourceManager;
    struct ResourceContext;
}

namespace sgc::asset {

    template<>
    struct AssetLoader<sgc::graphics::Tileset>
    {
        static std::shared_ptr<sgc::graphics::Tileset> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context,
            sgc::data::ResourceManager& rm
        );
    };

}