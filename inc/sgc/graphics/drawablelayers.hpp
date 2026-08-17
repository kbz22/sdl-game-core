#pragma once

#include "sgc/graphics/idrawable.hpp"
#include <memory>
#include <map>

namespace sgc::graphics {

    class DrawableLayers : public IDrawable {

        private:
            std::map<size_t, std::shared_ptr<IDrawable>> m_layers{};

        public:
            DrawableLayers() = default;

            void Set(size_t layerIndex, std::shared_ptr<IDrawable> drawable);
            void Insert(size_t layerIndex, std::shared_ptr<IDrawable> drawable);
            void Remove(size_t layerIndex);
            void Clear();

            std::shared_ptr<IDrawable> Get(size_t layerIndex) const;

            auto begin() { return m_layers.begin(); }
            auto end()   { return m_layers.end(); }

            auto begin() const { return m_layers.begin(); }
            auto end()   const { return m_layers.end(); }

            auto cbegin() const { return m_layers.cbegin(); }
            auto cend()   const { return m_layers.cend(); }

            void Draw(const RenderContext& context) override;

    };

}