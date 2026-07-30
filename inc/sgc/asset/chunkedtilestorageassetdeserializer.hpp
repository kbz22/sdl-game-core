#pragma once

#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include <memory>

namespace sgc::asset {

    template<>
    struct AssetDeserializer<sgc::asset::ChunkedTileStorageAsset>
    {
        static sgc::asset::ChunkedTileStorageAsset Deserialize(
            const std::vector<uint8_t>& data
        );
    };

}