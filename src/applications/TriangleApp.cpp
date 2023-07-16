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
    mShader = new Shader("../shaders/static.vert", "../shaders/lit.frag");
    mDisplayTexture = new Texture("../assets/textures/wall.jpg");

    mVertexArray = new VertexArray;
    mVertexPositions = new Attribute<vec3>;
    mVertexNormals = new Attribute<vec3>;
    mVertexTexCoords = new Attribute<vec2>;
    mIndexBuffer = new IndexBuffer;

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

    mat4 projection = perspective(60.0f, inAspectRatio, .01f, 1000.f);
    mat4 view = lookAt(vec3(0,0,1.f), vec3(0,0,0), vec3(0,1,0));
    mat4 model = glm::toMat4(angleAxis(mRotation * DEG2RAD, vec3(0, 0, 1)));

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

void TriangleApp::Shutdown() {
    delete mShader;
    delete mDisplayTexture;
    delete mVertexPositions;
    delete mVertexNormals;
    delete mVertexTexCoords;
    delete mIndexBuffer;
    delete mVertexArray;
}
