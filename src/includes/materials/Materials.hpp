#pragma once
#include "materials/BaseMaterial.hpp"

class QuadMaterial : public BaseMaterial{
    public:
        glm::mat4 modelMatrix, viewMatrix, projectionMatrix;
        QuadMaterial();
        ~QuadMaterial();

        void setUniformsOnInit() override;
        void updateUniforms() override;
};