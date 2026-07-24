#pragma once

#include "sgc/data/itilestorage.hpp"
#include "sgc/data/layertagid.hpp"
#include "sgc/text/text.hpp"
#include <vector>
#include <memory>

namespace sgc::data {

    class Layer 
    {
        private:
            std::vector<LayerTagId> tags;
            std::shared_ptr<ITileStorage> m_tileStorage;
            sgc::text::String m_name;

        public:
            Layer(std::shared_ptr<ITileStorage> tileStorage, std::vector<LayerTagId> tags = {});

            bool HasTag(LayerTagId tag) const;
    };

}