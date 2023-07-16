//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#include "IndexBuffer.h"
#include <glad/glad.h>

IndexBuffer::IndexBuffer() {
    glGenBuffers(1, &mHandle);
    mCount = 0;
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &mHandle);
}

unsigned int IndexBuffer::Count() const {
    return mCount;
}

unsigned int IndexBuffer::GetHandle() const {
    return mHandle;
}

void IndexBuffer::Set(unsigned int* inputArray, unsigned int arrayLengt) {
    mCount = arrayLengt;
    unsigned int size = sizeof(unsigned int);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * mCount, inputArray, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Set(std::vector<unsigned int>& input) {
    Set(&input[0], (unsigned int)input.size());
}

void IndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}