#pragma once

class VertexBuffer{
    unsigned int rendererId;

    public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void setData(const void* data, unsigned int size);
    void bind() const;
    void unbind() const;
};