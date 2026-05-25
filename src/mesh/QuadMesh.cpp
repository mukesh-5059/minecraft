#include <glad/glad.h>

#include "mesh/VertexArray.hpp"
#include "mesh/Meshes.hpp"

QuadMesh::QuadMesh(){

}

void QuadMesh::genVertexData(){
    const float vertices[] = {
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,

         0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f
    };
    vbo.bind();
    vbo.setData(vertices, sizeof(vertices));
}


void QuadMesh::genVertexArrayObject(){
    genVertexData();
    VertexArrayLayout vl;

    vl.add(GL_FLOAT, 3, GL_FALSE); 
    vl.add(GL_FLOAT, 3, GL_FALSE); 
    
    vao.bindLayout(vbo, vl);
}

void QuadMesh::render(){
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, vao.getVertexCount());
}

QuadMesh::~QuadMesh(){

}