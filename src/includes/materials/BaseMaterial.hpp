#pragma once
#include "materials/Shader.hpp"


class BaseMaterial{
    protected:
        ShaderProgram shaderProgram;

    public:
        BaseMaterial(std::string shaderName) : shaderProgram(shaderName){}
        virtual ~BaseMaterial(){}

        virtual void setUniformsOnInit(){}
        virtual void updateUniforms(){}
        void useMaterial(){shaderProgram.bind();}
};