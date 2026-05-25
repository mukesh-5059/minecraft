#include "mesh/BaseMesh.hpp"

class QuadMesh : public BaseMesh{
    public:
        QuadMesh();
        ~QuadMesh();

        void genVertexData() override;
        void genVertexArrayObject() override;
        void render() override;
};

class ChunkMesh : public BaseMesh{
    public:
        ChunkMesh();
        ~ChunkMesh();

        void genVertexData() override;
        void genVertexArrayObject() override;
        void render() override;
};