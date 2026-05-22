#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


void enableDebuggerFunc();

static glm::vec2 RESOLUTION(1920, 1080);
static float TARGET_FPS = 60.0f;
static float TARGET_FRAME_TIME = 1.0f / TARGET_FPS;

static glm::vec4 CLEAR_COLOR(0.07, 0.13, 0.17, 1.0);