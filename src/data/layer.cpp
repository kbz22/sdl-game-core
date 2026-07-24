#include "sgc/data/layer.hpp"

sgc::data::Layer::Layer(std::shared_ptr<ITileStorage> tileStorage, std::vector<LayerTagId> tags) :
    m_tileStorage(tileStorage),
    tags(tags) 
{}

bool sgc::data::Layer::HasTag(LayerTagId tag) const {
    for (const auto& t : tags) {
        if (t == tag) {
            return true;
        }
    }
    return false;
}