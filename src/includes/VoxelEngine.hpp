#pragma once

#include <GLFW/glfw3.h>

class VoxelEngine{
    bool enableDebugger;
    float dt;
    float time;
    GLFWwindow* window;

    public:
        VoxelEngine(bool enableDebugger = true);
        ~VoxelEngine();

        void update();
        void render();
        void handleEvents();
        void run();
        void imguiWindows();
};