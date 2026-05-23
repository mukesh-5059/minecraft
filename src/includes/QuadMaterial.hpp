#pragma once
#include "BaseMaterial.hpp"

class QuadMaterial : public BaseMaterial{
    public:
        QuadMaterial();
        ~QuadMaterial();

        void setUniformsOnInit();
        void updateUniforms();
};