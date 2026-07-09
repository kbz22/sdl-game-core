#include "sgc/graphics/multilayeredtiledimage.hpp"

sgc::graphics::MultilayeredTiledImage::MultilayeredTiledImage(const std::vector<std::shared_ptr<TiledImage>>& layers) :
    m_layers(layers)
{}

void sgc::graphics::MultilayeredTiledImage::Draw(const RenderContext& context)
{
    for (const auto& layer : m_layers) {        
        layer->Draw(context);
    }
}