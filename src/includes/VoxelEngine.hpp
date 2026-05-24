#pragma once

#include <GLFW/glfw3.h>
#include "Scene.hpp"
#include <memory>

class VoxelEngine{
    bool enableDebugger;
    float dt;
    float time;
    GLFWwindow* window;
    std::unique_ptr<Scene> scene;

    public:
        VoxelEngine(bool enableDebugger = true);
        ~VoxelEngine();

        void update();
        void render();
        void handleEvents();
        void run();
        void imguiWindows();
};