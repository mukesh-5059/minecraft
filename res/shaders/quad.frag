#version 330 core

in vec3 vertexColor;

out vec4 Fragcolor;

void main(){
   Fragcolor = vec4(vertexColor, 1.0);
}