#include "Scene.hpp"
#include "objects/Quad.hpp"


Scene::Scene() : quad(){

}

void Scene::render(){
    quad.render();
}

void Scene::update(){
    quad.update();
}

Scene::~Scene(){

}