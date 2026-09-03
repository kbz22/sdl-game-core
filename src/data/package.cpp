#include "sgc/data/package.hpp"
#include <fstream>

bool sgc::data::Package::Open(const std::filesystem::path& path)
{
    std::ifstream stream(path, std::ios::binary);

    if (!stream.is_open())
        return false;

    stream.seekg(0, std::ios::end);
    m_fileSize = static_cast<size_t>(stream.tellg());

    stream.seekg(0, std::ios::beg);

    if (m_fileSize == 0)
        return false;

    PackageHeader header;
    stream.read(reinterpret_cast<char*>(&header), sizeof(header));

    for (int i = 0; i < c_packageMagicSize; ++i) {
        if (header.magic[i] != c_packageMagic[i])
            return false;
    }

    m_dataOffset = header.dataOffset;

    // Read table
    stream.seekg(header.tableOffset);

    for (uint32_t i = 0; i < header.assetCount; i++)
    {
        PackageEntry entry;
        stream.read(reinterpret_cast<char*>(&entry), sizeof(entry));

        m_entries[entry.id] = entry;
    }

    if (m_dataOffset > m_fileSize)
        return false;

    stream.seekg(static_cast<std::streamoff>(m_dataOffset), std::ios::beg);
    m_data.resize(m_fileSize - m_dataOffset);
    stream.read(reinterpret_cast<char*>(m_data.data()), static_cast<std::streamsize>(m_data.size()));

    if (!stream && !stream.eof())
        return false;

    return true;
}

bool sgc::data::Package::Open(std::span<uint8_t> data)
{
    PackageHeader header;

    if(data.size() < sizeof(header))
        return false;

    std::memcpy(&header, data.data(), sizeof(header));

    for (int i = 0; i < c_packageMagicSize; ++i) {
        if (header.magic[i] != c_packageMagic[i])
            return false;
    }

    m_dataOffset = header.dataOffset;

    if(data.size() < sizeof(header) + header.assetCount * sizeof(PackageEntry))
        return false;

    for (uint32_t i = 0; i < header.assetCount; i++)
    {
        PackageEntry entry;       

        std::memcpy(&entry, data.data() + header.tableOffset + i * sizeof(entry), sizeof(entry));

        m_entries[entry.id] = entry;        
    }

    m_data = std::vector<uint8_t>(data.begin() + m_dataOffset, data.end());
    m_fileSize = data.size();

    return true;
}

std::vector<uint8_t> sgc::data::Package::ReadAssetData(AssetId id) const
{
    auto it = m_entries.find(id);
    if (it == m_entries.end())
        return {};

    const PackageEntry& entry = it->second;

    std::vector<uint8_t> data;

    if (entry.offset + entry.size > m_fileSize)
        return {};

    /* stream.seekg(entry.offset);
    stream.read(reinterpret_cast<char*>(data.data()), entry.size); */
    // std::memcpy(data.data(), m_data.data() + entry.offset, entry.size);
    data.insert(
        data.begin(),
        m_data.data() + entry.offset,
        m_data.data() + entry.offset + entry.size
    );

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