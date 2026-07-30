#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/data/asset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetDeserializer<AssetHeader>
    {
        public:
            static AssetHeader Deserialize(
                const std::vector<uint8_t> &data
            );
    };

}