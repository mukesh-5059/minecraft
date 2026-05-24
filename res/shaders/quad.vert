#version 330 core

layout(location = 0) in vec3 inPos;
layout(location = 1) in vec3 inColor;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

out vec3 vertexColor;

void main(){
    vertexColor = inColor;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(inPos, 1.0);
}