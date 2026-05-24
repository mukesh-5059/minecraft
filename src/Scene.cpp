#include "Scene.hpp"
#include "GLFW/glfw3.h"
#include "objects/Quad.hpp"


Scene::Scene() : quad(){

}

void Scene::render(){
    quad.render();
}

void Scene::update(GLFWwindow* window, float dt){
    quad.update(camera);
    camera.captureInput(window, dt);
}

Scene::~Scene(){

}