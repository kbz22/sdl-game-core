#include "sgc/graphics/renderlayer.hpp"

sgc::graphics::RenderLayer::RenderLayer(std::vector<std::shared_ptr<IDrawable>> drawables) :
    m_drawables(drawables)
{}

void sgc::graphics::RenderLayer::Draw(const RenderContext& context)
{
    for (const auto& drawable : m_drawables) {
        drawable->Draw(context);
    }
}