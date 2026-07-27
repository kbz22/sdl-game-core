#pragma once

#include "sgc/asset/chunkedtilestorageasset.hpp"
#include <variant>

namespace sgc::asset {

    using TileStorageAsset = std::variant<
        ChunkedTileStorageAsset
    >;

}