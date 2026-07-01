#pragma once

#include "sgc/data/chunkedtilestorage.hpp"
#include "sgc/asset/assetloader.hpp"
#include <memory>

namespace sgc::data
{
    class ResourceManager;
    struct ResourceContext;
}

namespace sgc::asset {

    template<>
    struct AssetLoader<sgc::data::ChunkedTileStorage>
    {
        static std::shared_ptr<sgc::data::ChunkedTileStorage> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context,
            sgc::data::ResourceManager& rm
        );
    };

}