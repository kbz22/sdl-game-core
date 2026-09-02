#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/data/asset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetDeserializer<AssetHeader>
    {
        static AssetHeader Deserialize(const std::vector<uint8_t> &data);
    };

    template<>
    struct AssetSerializer<AssetHeader>
    {
        public:
            static std::vector<uint8_t> Serialize(const AssetHeader &asset);
    };


}