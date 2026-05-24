#include <iostream>

#include <glad/glad.h>
#include "Settings.hpp"
#include "VoxelEngine.hpp"
#include "Scene.hpp"


#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

VoxelEngine::VoxelEngine(bool enableDebugger) : enableDebugger(enableDebugger), scene(){

    if (!glfwInit())
        exit(-1);

    if(enableDebugger) glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);  //debugging line
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(RESOLUTION.x, RESOLUTION.y, "iyan window", NULL, NULL);
    if (!window)
    { 
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);


    int version = gladLoadGL();
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context\n" << std::endl;
        exit(-1);
    }
    std::cout << "\nloaded " << glGetString(GL_VERSION) << std::endl;

    glViewport(0, 0, RESOLUTION.x, RESOLUTION.y);
    glClearColor(CLEAR_COLOR.x, CLEAR_COLOR.y, CLEAR_COLOR.z, CLEAR_COLOR.w);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if(enableDebugger) enableDebuggerFunc();  //debugging line

    scene = std::make_unique<Scene>();

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();

    dt = 0.0;
    time = 0.0;
}

void VoxelEngine::imguiWindows(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("FPS");
    ImGui::Text("dt: %.3f ms/frame", dt * 1000);
    ImGui::Text("FPS: %.1f", 1/dt);
    ImGui::Text("Runtime: %.2f", time);
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void VoxelEngine::update(){
    scene->update(window, dt);
}

void VoxelEngine::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    imguiWindows();
    scene->render();
    glfwSwapBuffers(window);
}

void VoxelEngine::handleEvents(){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

    glfwPollEvents();
}

void VoxelEngine::run(){
    float lastTime = 0.0f;

    while(!glfwWindowShouldClose(window)){
        time = glfwGetTime();
        if(time - lastTime < TARGET_FRAME_TIME){
                glfwPollEvents();
                continue;
            }
        dt = time - lastTime;
        lastTime = time;

        handleEvents();
        update();
        render();
    }

}

VoxelEngine::~VoxelEngine(){
    std::cout << "Closing Program" << std::endl;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}