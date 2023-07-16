//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &mHandle);
    mCount = 0;
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &mHandle);
}

unsigned int VertexArray::Count() const {
    return mCount;
}

unsigned int VertexArray::GetHandle() const {
    return mHandle;
}

void VertexArray::Bind() const {
    glBindVertexArray(mHandle);
}

void VertexArray::Unbind() {
    glBindVertexArray(0);
}