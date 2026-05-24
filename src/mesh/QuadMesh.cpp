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
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f
    };
    vbo.bind();
    vbo.setData(vertices, sizeof(vertices));
}

void QuadMesh::genIndexData(){
    const unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    ibo.bind();
    ibo.setData(indices, sizeof(indices) / sizeof(unsigned int));
}

void QuadMesh::genVertexArrayObject(){
    genVertexData();
    genIndexData();
    VertexArrayLayout vl;

    vl.add(GL_FLOAT, 3, GL_FALSE); 
    vl.add(GL_FLOAT, 3, GL_FALSE); 
    
    vao.bindLayout(vbo, vl);
}

void QuadMesh::render(){
    vao.bind();
    ibo.bind();
    glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, NULL);
}

QuadMesh::~QuadMesh(){

}