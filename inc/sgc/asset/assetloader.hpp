#pragma once

#include <memory>

namespace sgc::data {

    class ResourceManager;
    struct ResourceContext;

}

namespace sgc::asset {

    template<typename T>
    struct AssetLoader
    {
        static std::shared_ptr<T> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context,
            sgc::data::ResourceManager& rm
        );
    };

}