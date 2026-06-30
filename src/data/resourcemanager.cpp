#include "sgc/data/resourcemanager.hpp"
#include "sgc/data/asset.hpp"
#include <stdexcept>

void sgc::data::ResourceManager::Mount(Package* package)
{
    m_package = package;
}

/* std::shared_ptr<sgc::graphics::Image> sgc::data::ResourceManager::LoadImage(ResourceContext& context, AssetId id)
{
    auto it = m_images.find(id);

    if (it != m_images.end())
    {
        return it->second;
    }

    if(!m_package->HasAsset(id))
    {
        throw std::runtime_error("ResourceManager::LoadImage: Asset not found in package");
    }

    const auto& entry = m_package->GetEntry(id);

    if (entry.type != AssetType::Texture)
    {
        throw std::runtime_error("Asset is not a texture");
    }

    const auto data = m_package->ReadAssetData(id);

    auto image = std::make_shared<sgc::graphics::Image>();
    image->LoadTexture(context.renderer, data);
    m_images[id] = image;

    return m_images.at(id);
} */