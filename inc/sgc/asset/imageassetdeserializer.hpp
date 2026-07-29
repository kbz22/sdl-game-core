#pragma once

#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/imageasset.hpp"

namespace sgc::asset {

    using namespace sgc::data;

    template<>
    struct AssetDeserializer<ImageAsset>
    {
        public:
            static std::shared_ptr<ImageAsset> Load(
                const std::vector<uint8_t> &data,
                sgc::data::ResourceContext& context
            );
    };

}