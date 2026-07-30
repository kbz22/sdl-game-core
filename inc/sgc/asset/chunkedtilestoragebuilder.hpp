#pragma once

#include "sgc/data/chunkedtilestorage.hpp"
#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/asset/runtimebuilder.hpp"
#include <memory>

namespace sgc::asset {

    template<>
    struct RuntimeBuilder<sgc::data::ChunkedTileStorage>
    {
        static std::shared_ptr<sgc::data::ChunkedTileStorage> Build(const ChunkedTileStorageAsset& asset);
    };

}