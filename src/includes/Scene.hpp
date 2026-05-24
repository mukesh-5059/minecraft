#pragma once

#include "Camera.hpp"
#include "GLFW/glfw3.h"
#include "objects/Quad.hpp"

class Scene{
    Quad quad;
    Camera camera;

    public:
        Scene();
        ~Scene();

        void update(GLFWwindow *window, float dt);
        void render();
};