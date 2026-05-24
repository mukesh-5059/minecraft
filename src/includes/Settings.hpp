#pragma once 
#include "glm/trigonometric.hpp"
#include <glm/glm.hpp>

void enableDebuggerFunc();

static glm::vec2 RESOLUTION(1920, 1080);
static float ASPECT_RATIO = RESOLUTION.x / RESOLUTION.y;

static float TARGET_FPS = 60.0f;
static float TARGET_FRAME_TIME = 1.0f / TARGET_FPS;

static glm::vec4 CLEAR_COLOR(0.07, 0.13, 0.17, 1.0);

static float FOV_DEG = 45.0f;
static float V_FOV = glm::radians(FOV_DEG);
static float H_FOV = glm::atan(glm::tan(V_FOV * 0.5) * ASPECT_RATIO);
static float NEAR = 0.1;
static float FAR = 1000;
static float PITCH_MAX = 89.0f;