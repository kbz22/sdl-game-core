#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/data/asset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetSerializer<AssetHeader>
    {
        public:
            static std::vector<uint8_t> Serialize(const AssetHeader &asset);
    };

}