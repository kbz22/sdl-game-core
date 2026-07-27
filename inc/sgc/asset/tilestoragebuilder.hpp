#pragma once

#include "sgc/asset/assetbuilder.hpp"
#include "sgc/asset/tilestorageasset.hpp"
#include "sgc/data/itilestorage.hpp"

namespace sgc::asset {

    template<>
    struct AssetBuilder<TileStorageAsset>
    {
        public:
            static TileStorageAsset Build(const sgc::data::ITileStorage &asset);
    };

}