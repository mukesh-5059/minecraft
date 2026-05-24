#pragma once

#include "objects/Quad.hpp"

class Scene{
    Quad quad;

    public:
        Scene();
        ~Scene();

        void update();
        void render();
};