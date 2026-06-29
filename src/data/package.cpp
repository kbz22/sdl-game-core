#include "sgc/data/package.hpp"
#include <fstream>

bool sgc::data::Package::Open(const std::filesystem::path& path)
{
    m_stream.open(path, std::ios::binary);

    if (!m_stream.is_open())
        return false;

    m_stream.seekg(0, std::ios::end);
    m_fileSize = static_cast<size_t>(m_stream.tellg());

    m_stream.seekg(0, std::ios::beg);

    if (m_fileSize == 0)
        return false;

    PackageHeader header;
    m_stream.read(reinterpret_cast<char*>(&header), sizeof(header));

    if (header.magic[0] != 'S' ||
        header.magic[1] != 'G' ||
        header.magic[2] != 'C' ||
        header.magic[3] != 'P')
        return false;

    m_dataOffset = header.dataOffset;

    // Read table
    m_stream.seekg(header.tableOffset);

    for (uint32_t i = 0; i < header.assetCount; i++)
    {
        PackageEntry entry;
        m_stream.read(reinterpret_cast<char*>(&entry), sizeof(entry));

        m_entries[entry.id] = entry;
    }

    return true;
}

std::vector<uint8_t> sgc::data::Package::ReadAssetData(AssetId id) const
{
    auto it = m_entries.find(id);
    if (it == m_entries.end())
        return {};

    const PackageEntry& entry = it->second;

    std::vector<uint8_t> data(entry.size);

    if (entry.offset + entry.size > m_fileSize)
        return {};

    m_stream.seekg(entry.offset);
    m_stream.read(reinterpret_cast<char*>(data.data()), entry.size);

    return data;
}

bool sgc::data::Package::HasAsset(AssetId id) const
{
    return m_entries.find(id) != m_entries.end();
}

const sgc::data::PackageEntry& sgc::data::Package::GetEntry(AssetId id) const
{
    auto it = m_entries.find(id);
    if (it == m_entries.end())
        throw std::runtime_error("Asset not found in package");

    return it->second;
}