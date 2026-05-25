#pragma once

class VertexBuffer{
    unsigned int rendererId;
    unsigned int bufferSize;

    public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void setData(const void* data, unsigned int size);
    void bind() const;
    void unbind() const;
    unsigned int getBufferSize() const {return bufferSize;}
};