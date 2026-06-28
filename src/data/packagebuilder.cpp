#include "sgc/data/packagebuilder.hpp"
#include "sgc/data/package.hpp"
#include <fstream>

void sgc::data::PackageBuilder::AddAsset(
    AssetId id,
    AssetType type,
    const std::vector<uint8_t>& data)
{
    m_assets.push_back({ id, type, data });
}

bool sgc::data::PackageBuilder::Save(const std::filesystem::path& path)
{
    std::ofstream out(path, std::ios::binary);

    if (!out.is_open())
        return false;

    PackageHeader header{};
    header.magic[0] = 'S';
    header.magic[1] = 'G';
    header.magic[2] = 'C';
    header.magic[3] = 'P';
    header.version = 1;
    header.assetCount = static_cast<uint32_t>(m_assets.size());

    header.tableOffset = sizeof(PackageHeader);
    header.dataOffset = 0; // we'll compute later

    //! placeholder header
    out.write(reinterpret_cast<char*>(&header), sizeof(header));

    std::vector<PackageEntry> entries;

    uint32_t offset = sizeof(PackageHeader)
                    + m_assets.size() * sizeof(PackageEntry);

    header.dataOffset = offset;

    // write table + data
    for (auto& a : m_assets)
    {
        PackageEntry e{};
        e.id = a.id;
        e.type = a.type;
        e.offset = offset;
        e.size = a.data.size();

        entries.push_back(e);

        offset += e.size;
    }

    // write entries
    out.write(reinterpret_cast<char*>(entries.data()),
              entries.size() * sizeof(PackageEntry));

    // write asset data
    for (auto& a : m_assets)
    {
        out.write(reinterpret_cast<char*>(a.data.data()),
                  a.data.size());
    }

    return true;
}