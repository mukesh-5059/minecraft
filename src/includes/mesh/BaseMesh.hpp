#pragma once 
#include "mesh/VertexArray.hpp"
#include "mesh/IndexBuffer.hpp"
#include <glm/glm.hpp>

class BaseMesh{
    protected:
        VertexArray vao;
        VertexBuffer vbo;
        IndexBuffer ibo;

    public:
        BaseMesh();
        ~BaseMesh();

        virtual void genVertexData();
        virtual void genIndexData();
        virtual void genVertexArrayObject();
};