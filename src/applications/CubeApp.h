//
// Created by Mohamad Harits Nur Fauzan on 16/07/23.
//

#ifndef ANIMATIONPROGRAMMING_CUBEAPP_H
#define ANIMATIONPROGRAMMING_CUBEAPP_H

#include "Application.h"
#include "../opengl/Shader.h"
#include "../opengl/Attribute.h"
#include "../opengl/VertexArray.h"
#include "../opengl/Texture.h"

#include <glm/glm.hpp>
#include <memory>

class CubeApp : public Application {
protected:
    std::unique_ptr<Shader> mShader;
    std::unique_ptr<Attribute<glm::vec3>> mVertexPositions;
    std::unique_ptr<Attribute<glm::vec3>> mVertexNormals;
    std::unique_ptr<Attribute<glm::vec2>> mVertexTexCoords;
    std::unique_ptr<VertexArray> mVertexArray;
    std::unique_ptr<Texture> mDisplayTexture;

public:
    void Initialize();
    void Update(float inDeltaTime);
    void Render(float inAspectRatio);
    void Shutdown();
};


#endif //ANIMATIONPROGRAMMING_CUBEAPP_H
