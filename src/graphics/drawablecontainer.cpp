#include "sgc/graphics/drawablecontainer.hpp"

sgc::graphics::DrawableContainer::DrawableContainer(std::vector<std::shared_ptr<IDrawable>> drawables) :
    m_drawables(drawables)
{}

void sgc::graphics::DrawableContainer::Draw(const RenderContext& context)
{
    for (const auto& drawable : m_drawables) {
        drawable->Draw(context);
    }
}