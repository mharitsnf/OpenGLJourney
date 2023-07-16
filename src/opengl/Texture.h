//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_TEXTURE_H
#define ANIMATIONPROGRAMMING_TEXTURE_H

class Texture {
protected:
    unsigned int mWidth;
    unsigned int mHeight;
    unsigned int mChannels;
    unsigned int mHandle;

private:
    Texture(const Texture& other);
    Texture& operator=(const Texture& other);

public:
    Texture();
    Texture(const char* path);
    ~Texture();

    void Load(const char* path);

    void Set(unsigned int uniformIndex, unsigned int textureIndex);
    void UnSet(unsigned int textureIndex);

    unsigned int GetHandle();
};


#endif //ANIMATIONPROGRAMMING_TEXTURE_H
