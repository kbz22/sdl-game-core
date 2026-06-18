#pragma once

namespace sgc::graphics {

    struct Viewport {
        float x;
        float y;
        float width;
        float height;
    };

    struct View {
        Viewport camera;
        Viewport screen;
    };

}