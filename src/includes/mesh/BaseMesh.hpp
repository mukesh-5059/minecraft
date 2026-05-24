#pragma once 
#include "mesh/VertexArray.hpp"
#include "mesh/IndexBuffer.hpp"
#include <glm/glm.hpp>

class BaseMesh{
    protected:
        VertexArray vao;
        VertexBuffer vbo;
        IndexBuffer ibo;
        virtual void genVertexData(){}
        virtual void genIndexData(){}

    public:
        BaseMesh(){}
        virtual ~BaseMesh(){}

        virtual void genVertexArrayObject(){}
        virtual void render(){}
};