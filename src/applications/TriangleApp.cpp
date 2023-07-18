//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#include "TriangleApp.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "../opengl/Uniform.h"
#include "../opengl/Draw.h"

void TriangleApp::Initialize() {
    using namespace glm;

    mRotation = 0;
    mShader = std::make_unique<Shader>("../shaders/static.vert", "../shaders/lit.frag");
    mDisplayTexture = std::make_unique<Texture>("../assets/textures/wall.jpg");

    mVertexArray = std::make_unique<VertexArray>();
    mVertexPositions = std::make_unique<Attribute<vec3>>();
    mVertexNormals = std::make_unique<Attribute<vec3>>();
    mVertexTexCoords = std::make_unique<Attribute<vec2>>();
    mIndexBuffer = std::make_unique<IndexBuffer>();

    // Vertex positions
    std::vector<vec3> positions;
    positions.emplace_back(-1, -1, 0);
    positions.emplace_back(-1, 1, 0);
    positions.emplace_back(1, -1, 0);
    positions.emplace_back(1, 1, 0);

    // Setting up the bindings
    mVertexArray->Bind();
    mVertexPositions->Set(positions);
    mVertexPositions->BindTo(mShader->GetAttribute("position"));
    mVertexArray->Unbind();

    // Normal vectors
    std::vector<vec3> normals;
    normals.resize(4, vec3(0, 0, 1));

    // Bind the normal to OpenGL
    mVertexArray->Bind();
    mVertexNormals->Set(normals);
    mVertexNormals->BindTo(mShader->GetAttribute("normal"));
    mVertexArray->Unbind();

    // UV coordinates
    std::vector<vec2> uvs;
    uvs.emplace_back(0, 0);
    uvs.emplace_back(0, 1);
    uvs.emplace_back(1, 0);
    uvs.emplace_back(1, 1);

    // Bind UV to OpenGL
    mVertexArray->Bind();
    mVertexTexCoords->Set(uvs);
    mVertexTexCoords->BindTo(mShader->GetAttribute("texCoord"));
    mVertexArray->Unbind();

    // Indices
    std::vector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(3);

    // Bind and apply indices to OpenGL
    mVertexArray->Bind();
    mIndexBuffer->Set(indices);
    mVertexArray->Unbind();
}

void TriangleApp::Update(float inDeltaTime) {
    mRotation += inDeltaTime * 45.0f;
    while (mRotation > 360.0f) {
        mRotation -= 360.0f;
    }
}

void TriangleApp::Render(float inAspectRatio) {
    using namespace glm;

    mat4 projection = perspective(50.0f, inAspectRatio, .01f, 1000.f);
    mat4 view = lookAt(vec3(0,0,-10.f), vec3(0,0,0), vec3(0,1,0));

    // Left to right order, e.g., float result = ((a * b) * c) * d;
    mat4 model = mat4(1.0f) * glm::toMat4(angleAxis(radians(-60.f), vec3(1, 0, 0))) * glm::toMat4(angleAxis(radians(mRotation), vec3(0, 0, 1)));

    mShader->Bind();

    // Feed the data to the uniform in the shader
    Uniform<mat4>::Set(mShader->GetUniform("model"), model);
    Uniform<mat4>::Set(mShader->GetUniform("view"), view);
    Uniform<mat4>::Set(mShader->GetUniform("projection"), projection);
    Uniform<vec3>::Set(mShader->GetUniform("light"), vec3(0, 0, 1));
    mDisplayTexture->Set(mShader->GetUniform("tex0"), 0);

    Anim::Draw(*mIndexBuffer, *mVertexArray, DrawMode::Triangles);

    mDisplayTexture->UnSet(0);
    mShader->UnBind();
}
