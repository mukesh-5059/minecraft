#pragma once

#include "Camera.hpp"
#include "GLFW/glfw3.h"
#include "objects/Quad.hpp"

class Scene{
    Quad quad;

    public:
        Camera camera;
        Scene();
        ~Scene();

        void update(GLFWwindow *window, float dt);
        void render();
};