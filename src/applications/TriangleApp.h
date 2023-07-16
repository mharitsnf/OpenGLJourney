//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_TRIANGLEAPP_H
#define ANIMATIONPROGRAMMING_TRIANGLEAPP_H

#include "Application.h"
#include "../opengl/Shader.h"
#include "../opengl/Attribute.h"
#include "../opengl/IndexBuffer.h"
#include "../opengl/VertexArray.h"
#include "../opengl/Texture.h"
#include <glm/glm.hpp>

#define DEG2RAD 0.0174533f

class TriangleApp : public Application {
protected:
    Shader* mShader;
    Attribute<glm::vec3>* mVertexPositions;
    Attribute<glm::vec3>* mVertexNormals;
    Attribute<glm::vec2>* mVertexTexCoords;
    IndexBuffer* mIndexBuffer;
    VertexArray* mVertexArray;
    Texture* mDisplayTexture;
    float mRotation;

public:
    void Initialize();
    void Update(float inDeltaTime);
    void Render(float inAspectRatio);
    void Shutdown();
};


#endif //ANIMATIONPROGRAMMING_TRIANGLEAPP_H
