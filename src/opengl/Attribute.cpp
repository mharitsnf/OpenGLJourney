//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#include "Attribute.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

template<typename T>
Attribute<T>::Attribute() {
    glGenBuffers(1, &mHandle);
    mCount = 0;
}

template<typename T>
Attribute<T>::~Attribute() {
    glDeleteBuffers(1, &mHandle);
}

template<typename T>
unsigned int Attribute<T>::Count() {
    return mCount;
}

template<typename T>
unsigned int Attribute<T>::GetHandle() {
    return mHandle;
}

template<typename T>
void Attribute<T>::Set(T* inputArray, unsigned int arrayLength) {
    mCount = arrayLength;
    unsigned int size = sizeof(T);

    glBindBuffer(GL_ARRAY_BUFFER, mHandle); // bind buffer
    glBufferData(GL_ARRAY_BUFFER, size * mCount, inputArray, GL_STREAM_DRAW); // set the buffer data
    glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind buffer
}

template<typename T>
void Attribute<T>::Set(std::vector<T>& input) {
    Set(&input[0], (unsigned int)input.size());
}

template<typename T>
void Attribute<T>::BindTo(unsigned int slot) {
    glBindBuffer(GL_ARRAY_BUFFER, mHandle); // bind again the buffer
    glEnableVertexAttribArray(slot);
    SetAttribPointer(slot);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind
}

template<typename T>
void Attribute<T>::UnBindFrom(unsigned int slot) {
    glBindBuffer(GL_ARRAY_BUFFER, mHandle);
    glDisableVertexAttribArray(slot);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

template<>
void Attribute<int>::SetAttribPointer(unsigned int slot) {
    glVertexAttribIPointer(slot, 1, GL_INT, 0, (void*)0);
}

template<>
void Attribute<glm::ivec4>::SetAttribPointer(unsigned int slot) {
    glVertexAttribIPointer(slot, 4, GL_INT, 0, (void*)0);
}

template<>
void Attribute<float>::SetAttribPointer(unsigned int slot) {
    glVertexAttribPointer(slot, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void Attribute<glm::vec2>::SetAttribPointer(unsigned int slot) {
    glVertexAttribPointer(slot, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void Attribute<glm::vec3>::SetAttribPointer(unsigned int slot) {
    glVertexAttribPointer(slot, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void Attribute<glm::vec4>::SetAttribPointer(unsigned int slot) {
    glVertexAttribPointer(slot, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template<>
void Attribute<glm::quat>::SetAttribPointer(unsigned int slot) {
    glVertexAttribPointer(slot, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

template class Attribute<int>;
template class Attribute<float>;
template class Attribute<glm::vec2>;
template class Attribute<glm::vec3>;
template class Attribute<glm::vec4>;
template class Attribute<glm::ivec4>;
template class Attribute<glm::quat>;