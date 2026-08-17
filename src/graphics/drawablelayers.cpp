#include "sgc/graphics/drawablelayers.hpp"

void sgc::graphics::DrawableLayers::Set(size_t layerIndex, std::shared_ptr<IDrawable> drawable)
{
    m_layers[layerIndex] = drawable;
}

void sgc::graphics::DrawableLayers::Insert(size_t layerIndex, std::shared_ptr<IDrawable> drawable)
{
    m_layers.insert({layerIndex, drawable});
}

void sgc::graphics::DrawableLayers::Remove(size_t layerIndex)
{
    m_layers.erase(layerIndex);
}

void sgc::graphics::DrawableLayers::Clear()
{
    m_layers.clear();
}

std::shared_ptr<sgc::graphics::IDrawable> sgc::graphics::DrawableLayers::Get(size_t layerIndex) const
{
    auto it = m_layers.find(layerIndex);
    if (it != m_layers.end()) {
        return it->second;
    }
    return nullptr;
}

void sgc::graphics::DrawableLayers::Draw(const RenderContext& context)
{
    for (const auto& [layerIndex, drawable] : m_layers) {
        if (drawable) {
            drawable->Draw(context);
        }
    }
}
