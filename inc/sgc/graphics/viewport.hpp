#pragma once

namespace sgc::graphics {

    struct Viewport {
        float x;
        float y;
        float w;
        float h;
    };

    struct View {
        Viewport camera;
        Viewport screen;
    };

}