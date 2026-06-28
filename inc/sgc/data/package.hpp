#pragma once

#include "sgc/data/asset.hpp"
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <filesystem>
#include <vector>

namespace sgc::data {

    struct PackageHeader {
        char magic[4];
        uint32_t version;
        uint32_t assetCount;
        uint32_t tableOffset;
        uint32_t dataOffset;
    };

    struct PackageEntry {
        AssetId id;
        AssetType type;
        uint32_t offset;
        uint32_t size;
    };

    class Package {

    private:
        mutable std::ifstream m_stream;
        std::unordered_map<AssetId, PackageEntry> m_entries;
        uint32_t m_dataOffset = 0;
        size_t m_fileSize = 0;
            
    public:
        bool Open(const std::filesystem::path& path);
        bool Save(const std::filesystem::path& path); // optional for now

        bool HasAsset(AssetId id) const;

        const PackageEntry& GetEntry(AssetId id) const;

        std::vector<uint8_t> ReadAssetData(AssetId id) const;

    
    };

}