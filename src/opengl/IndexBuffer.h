//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_INDEXBUFFER_H
#define ANIMATIONPROGRAMMING_INDEXBUFFER_H

#include <vector>

class IndexBuffer {
public:
    unsigned int mHandle;
    unsigned int mCount;

private:
    IndexBuffer(const IndexBuffer& other);
    IndexBuffer& operator=(const IndexBuffer& other);

public:
    IndexBuffer();
    ~IndexBuffer();

    void Set(unsigned int* inputArray, unsigned int arrayLengt);
    void Set(std::vector<unsigned int>& input);
    void Unbind();

    unsigned int Count() const;
    unsigned int GetHandle() const;
};


#endif //ANIMATIONPROGRAMMING_INDEXBUFFER_H
