#pragma once
#include "materials/BaseMaterial.hpp"

class QuadMaterial : public BaseMaterial{
    public:
        QuadMaterial();
        ~QuadMaterial();

        void setUniformsOnInit();
        void updateUniforms();
};