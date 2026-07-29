#pragma once

#include <memory>
#include <vector>

namespace sgc::data {
    struct ResourceContext;
}

namespace sgc::asset {

    template<typename T>
    struct AssetDeserializer
    {
        static std::shared_ptr<T> Load(
            const std::vector<uint8_t>& data,
            sgc::data::ResourceContext& context
        );
    };

}