#pragma once

#include "sgc/asset/assetserializer.hpp"
#include "sgc/asset/chunkedtilestorageasset.hpp"

namespace sgc::asset {

    template<>
    struct AssetSerializer<ChunkedTileStorageAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const ChunkedTileStorageAsset &asset);
    };

}