#pragma once 
#include "mesh/VertexArray.hpp"
#include <glm/glm.hpp>

class BaseMesh{
    protected:
        VertexArray vao;
        VertexBuffer vbo;

    public:
        BaseMesh(){}
        virtual ~BaseMesh(){}

        virtual void genVertexData(){}
        virtual void genVertexArrayObject(){}
        virtual void render(){}
};