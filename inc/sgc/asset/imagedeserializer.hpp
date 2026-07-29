#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/data/resourcecontext.hpp"
#include "sgc/data/resourcemanager.hpp"
#include "sgc/asset/assetdeserializer.hpp"

namespace sgc::asset {

    template<>
    struct AssetDeserializer<sgc::graphics::Image>
    {
        static std::shared_ptr<sgc::graphics::Image> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context,
            sgc::data::ResourceManager& rm
        );
    };

}