#pragma once

class IndexBuffer{
    unsigned int rendererId;
    unsigned int count;

    public:
    IndexBuffer();
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void setData(const unsigned int* data, unsigned int count);
    void bind() const;
    void unbind() const;
    unsigned int getCount() const;
};