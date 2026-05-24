#include "mesh/BaseMesh.hpp"

class QuadMesh : public BaseMesh{
    void genVertexData() override;
    void genIndexData() override;

    public:
        QuadMesh();
        ~QuadMesh();
        void genVertexArrayObject() override;
        void render() override;
};