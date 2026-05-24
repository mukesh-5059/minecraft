#pragma once

#include "mesh/Meshes.hpp"
#include "materials/Materials.hpp"

class Quad{
    QuadMaterial material;
    QuadMesh mesh;
    glm::vec3 pos, rotation;

    public:
        Quad();
        ~Quad();

        void render();
        void update();
};