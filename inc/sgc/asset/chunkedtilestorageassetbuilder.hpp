#pragma once

#include "sgc/asset/assetbuilder.hpp"
#include "sgc/asset/chunkedtilestorageasset.hpp"

namespace sgc::data {
    class ChunkedTileStorage;
}

namespace sgc::asset {

    template<>
    struct AssetBuilder<ChunkedTileStorageAsset>
    {
        static ChunkedTileStorageAsset Build(const data::ChunkedTileStorage &storage);
    };

}