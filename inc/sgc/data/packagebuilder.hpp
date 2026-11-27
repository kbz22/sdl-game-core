#pragma once

#include "sgc/data/asset.hpp"
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace sgc::data 
{
    struct PackageBuilderEntry {
        AssetHeader header;
        std::vector<uint8_t> data;
    };

    class PackageBuilder
    {
        private:            
            std::unordered_map<AssetId, PackageBuilderEntry> m_assetMap;

        public:
            void AddAsset(
                AssetId id,
                AssetType type,
                const std::vector<uint8_t>& data
            );

            void AddAsset(const PackageBuilderEntry &asset);

            bool Save(const std::filesystem::path& path);
            std::vector<uint8_t> Build();
    };

}