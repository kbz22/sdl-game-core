#pragma once

namespace sgc::graphics {

    struct RenderContext;
    
    class IDrawable {
        public:
            virtual ~IDrawable() = default;
            virtual void Draw(const RenderContext& context) = 0;            
    };

}