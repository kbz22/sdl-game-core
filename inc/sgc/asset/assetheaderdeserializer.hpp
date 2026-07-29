#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/data/asset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetDeserializer<AssetHeader>
    {
        public:
            static std::shared_ptr<AssetHeader> Load(
                const std::vector<uint8_t> &data,
                sgc::data::ResourceContext& context,
                sgc::data::ResourceManager& rm
            );
    };

}