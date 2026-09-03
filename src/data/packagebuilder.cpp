#include "sgc/data/packagebuilder.hpp"
#include "sgc/data/package.hpp"
#include "sgc/asset/assetheader.hpp"
#include <fstream>

void sgc::data::PackageBuilder::AddAsset(
    AssetId id,
    AssetType type,
    const std::vector<uint8_t>& data)
{
    // m_assets.push_back({ { id, type, data.size() }, data });
    m_assetMap[id] = { { id, type, data.size() }, data };
}

void sgc::data::PackageBuilder::AddAsset(
    BinaryAsset asset
)
{
    // m_assets.push_back(asset);
    m_assetMap[asset.header.id] = asset;
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
    header.assetCount = static_cast<uint32_t>(m_assetMap.size());

    header.tableOffset = sizeof(PackageHeader);
    header.dataOffset = 0;    

    std::vector<PackageEntry> entries;

    size_t dataOffset = sizeof(PackageHeader) + m_assetMap.size() * sizeof(PackageEntry);
    header.dataOffset = dataOffset;

    out.write(reinterpret_cast<char*>(&header), sizeof(header));

    size_t offset = 0;

    // write table + data
    // for (auto& a : m_assets)
    for (auto& [id, a] : m_assetMap)
    {
        PackageEntry e{};
        e.id = a.header.id;
        e.type = a.header.type;
        e.offset = offset;
        e.size = a.data.size();

        entries.push_back(e);

        offset += e.size;
    }

    // write entries
    out.write(reinterpret_cast<char*>(entries.data()),
              entries.size() * sizeof(PackageEntry));

    // write asset data
    // for (auto& a : m_assets)
    for (auto& [id, a] : m_assetMap)
    {
        out.write(reinterpret_cast<char*>(a.data.data()),
                  a.data.size());
    }

    return true;
}

std::vector<uint8_t> sgc::data::PackageBuilder::Build()
{        
    PackageHeader header{};
    std::memcpy(header.magic, sgc::data::c_packageMagic, sgc::data::c_packageMagicSize);
    header.version = 1;
    header.assetCount = static_cast<uint32_t>(m_assetMap.size());
    header.tableOffset = sizeof(PackageHeader);

    size_t dataOffset = sizeof(PackageHeader) + m_assetMap.size() * sizeof(PackageEntry);
    header.dataOffset = dataOffset;

    std::vector<uint8_t> data;    
    data.insert(
        data.end(),
        reinterpret_cast<uint8_t*>(&header),
        reinterpret_cast<uint8_t*>(&header) + sizeof(PackageHeader)
    );

    size_t offset = 0;
    
    for (auto& [id, a] : m_assetMap) // table
    {
        PackageEntry e{};
        e.id = a.header.id;
        e.type = a.header.type;
        e.offset = offset;
        e.size = a.data.size();

        data.insert(
            data.end(),
            reinterpret_cast<uint8_t*>(&e),
            reinterpret_cast<uint8_t*>(&e) + sizeof(PackageEntry)
        );

        offset += e.size;
    }

    for (auto& [id, a] : m_assetMap) // data
    {
        data.insert(
            data.end(),
            a.data.begin(),
            a.data.end()
        );
    }

    return data;
}