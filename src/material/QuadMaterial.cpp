#include "materials/Materials.hpp"

QuadMaterial::QuadMaterial() : BaseMaterial("quad"){
    setUniformsOnInit();
}

void QuadMaterial::setUniformsOnInit(){
    shaderProgram.bind();
    shaderProgram.setMat4f("projectionMatrix", projectionMatrix);
    shaderProgram.setMat4f("modelMatrix", modelMatrix);
    shaderProgram.setMat4f("viewMatrix", viewMatrix);
}

void QuadMaterial::updateUniforms(){
    shaderProgram.bind();
    shaderProgram.setMat4f("projectionMatrix", projectionMatrix);
    shaderProgram.setMat4f("modelMatrix", modelMatrix);
    shaderProgram.setMat4f("viewMatrix", viewMatrix);
}

QuadMaterial::~QuadMaterial(){

}