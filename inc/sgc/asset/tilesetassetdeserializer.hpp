#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/tilesetasset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetDeserializer<TilesetAsset>
    {
        public:
            static std::shared_ptr<TilesetAsset> Load(
                const std::vector<uint8_t> &data,
                sgc::data::ResourceContext& context
            );
    };

}