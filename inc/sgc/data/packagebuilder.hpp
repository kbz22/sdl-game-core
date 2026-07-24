#pragma once

#include "sgc/data/asset.hpp"
#include <vector>
#include <filesystem>

namespace sgc::data {

    class PackageBuilder
    {
    public:
        void AddAsset(
            AssetId id,
            AssetType type,
            const std::vector<uint8_t>& data
        );

        void AddAsset(
            BinaryAsset asset
        );

        bool Save(const std::filesystem::path& path);

    private:
        std::vector<BinaryAsset> m_assets;
    };

}