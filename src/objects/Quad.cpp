#include "objects/Quad.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include "materials/Materials.hpp"
#include <glm/gtc/matrix_transform.hpp>


glm::mat4 Quad::baseMatrix(1.0);

Quad::Quad() : material(), mesh(),
               pos(0.0), rotation(0.0), scale(1.0) {
    mesh.genVertexArrayObject();
}

void Quad::render(){
    material.useMaterial();
    mesh.render();
}

void Quad::update(Camera &camera){
    glm::mat4 modelMatrix = glm::translate(baseMatrix, pos);

    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
    
    modelMatrix = glm::scale(modelMatrix, scale);
    material.modelMatrix = modelMatrix;
    material.projectionMatrix = camera.getProjectionMatrix();
    material.viewMatrix = camera.getViewMatrix();
    material.updateUniforms();
}

Quad::~Quad(){

}
