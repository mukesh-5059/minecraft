#pragma once

#include <Settings.hpp>

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