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
#include <memory>

class TriangleApp : public Application {
protected:
    std::unique_ptr<Shader> mShader;
    std::unique_ptr<Attribute<glm::vec3>> mVertexPositions;
    std::unique_ptr<Attribute<glm::vec3>> mVertexNormals;
    std::unique_ptr<Attribute<glm::vec2>> mVertexTexCoords;
    std::unique_ptr<IndexBuffer> mIndexBuffer;
    std::unique_ptr<VertexArray> mVertexArray;
    std::unique_ptr<Texture> mDisplayTexture;
    float mRotation;

public:
    void Initialize() override;
    void Update(float inDeltaTime) override;
    void Render(float inAspectRatio) override;
};


#endif //ANIMATIONPROGRAMMING_TRIANGLEAPP_H
