#include "objects/Quad.hpp"
#include "materials/Materials.hpp"

Quad::Quad() : material(), mesh(),
               pos(0.0), rotation(0.0) {
    mesh.genVertexArrayObject();
}

void Quad::render(){
    material.useMaterial();
    mesh.render();
}

void Quad::update(){
    material.updateUniforms();
}

Quad::~Quad(){
    
}
