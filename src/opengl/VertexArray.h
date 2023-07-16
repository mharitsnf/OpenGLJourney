//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_VERTEXARRAY_H
#define ANIMATIONPROGRAMMING_VERTEXARRAY_H


class VertexArray {
public:
    unsigned int mHandle;
    unsigned int mCount;

public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind();

    unsigned int Count() const;
    unsigned int GetHandle() const;
};


#endif //ANIMATIONPROGRAMMING_VERTEXARRAY_H
