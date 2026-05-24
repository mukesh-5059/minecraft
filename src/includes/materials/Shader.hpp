#pragma once

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>


class ShaderProgram{
    unsigned int rendererId;
    std::unordered_map<std::string, unsigned int> uniforms;

    public:
        ShaderProgram(std::string shaderName);
        ~ShaderProgram();

        unsigned int getUniformLocation(std::string uniform);
        void bind() const;

        void setInt(std::string uniform, int n);
        void setFloat(std::string uniform, float n);
        void setVec4f(std::string uniform, glm::vec4 vec4);
        void setVec3f(std::string uniform, glm::vec3 vec3);
        void setMat4f(std::string uniform, glm::mat4 &mat);
};