#include <glad/glad.h>
#include <mesh/IndexBuffer.hpp>

IndexBuffer::IndexBuffer() : rendererId(0), count(0){
    glGenBuffers(1, &rendererId);
}

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
 : rendererId(0), count(count){
    glGenBuffers(1, &rendererId);
    bind();
    setData(data, count);
}

void IndexBuffer::setData(const unsigned int* data, unsigned int count){
    this->count = count;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

void IndexBuffer::bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
}

void IndexBuffer::unbind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::getCount() const{
    return count;
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &rendererId);
}
