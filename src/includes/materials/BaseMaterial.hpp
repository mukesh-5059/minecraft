#pragma once
#include "Shader.hpp"


class BaseMaterial{
    protected:
        ShaderProgram shaderProgram;

    public:
        BaseMaterial(std::string shaderName) : shaderProgram(shaderName){}
        ~BaseMaterial(){}

        virtual void setUniformsOnInit(){}
        virtual void updateUniforms(){}
        void useMaterial(){shaderProgram.bind();}
};