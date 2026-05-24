#pragma once

#include "Camera.hpp"
#include "mesh/Meshes.hpp"
#include "materials/Materials.hpp"

class Quad{
    QuadMaterial material;
    QuadMesh mesh;
    glm::vec3 pos, rotation, scale;
    static glm::mat4 baseMatrix;

    public:
        Quad();
        ~Quad();

        void render();
        void update(Camera &camera);
};