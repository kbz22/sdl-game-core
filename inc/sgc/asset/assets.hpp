#pragma once

#include "sgc/asset/mapasset.hpp"
#include "sgc/asset/imageasset.hpp"
#include "sgc/asset/tilesetasset.hpp"
#include "sgc/asset/metadataasset.hpp"
#include "sgc/asset/binaryasset.hpp"

namespace sgc::asset
{
    using AssetVariant = std::variant<
        std::shared_ptr<sgc::asset::BinaryAsset>,
        std::shared_ptr<sgc::asset::ImageAsset>,
        std::shared_ptr<sgc::asset::TilesetAsset>,
        std::shared_ptr<sgc::asset::MapAsset>,
        std::shared_ptr<sgc::asset::AssetMetadata>
    >;
}
