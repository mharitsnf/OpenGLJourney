//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#include "Draw.h"
#include <glad/glad.h>
#include <iostream>

static GLenum DrawModeToGLEnum(DrawMode input) {
    if (input == DrawMode::Points) {
        return  GL_POINTS;
    }
    else if (input == DrawMode::LineStrip) {
        return GL_LINE_STRIP;
    }
    else if (input == DrawMode::LineLoop) {
        return  GL_LINE_LOOP;
    }
    else if (input == DrawMode::Lines) {
        return  GL_LINES;
    }
    else if (input == DrawMode::Triangles) {
        return  GL_TRIANGLES;
    }
    else if (input == DrawMode::TriangleStrip) {
        return  GL_TRIANGLE_STRIP;
    }
    else if (input == DrawMode::TriangleFan) {
        return   GL_TRIANGLE_FAN;
    }

    std::cout << "DrawModeToGLEnum unreachable code hit\n";
    return 0;
}

void Anim::Draw(unsigned int vertexCount, VertexArray& inVertexArray, DrawMode mode) {
    inVertexArray.Bind();
    glDrawArrays(DrawModeToGLEnum(mode), 0, vertexCount);
    inVertexArray.Unbind();
}

void Anim::Draw(IndexBuffer &inIndexBuffer, VertexArray &inVertexArray, DrawMode mode) {
    unsigned int handle = inIndexBuffer.GetHandle();
    unsigned int numIndices = inIndexBuffer.Count();

    inVertexArray.Bind();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);
    glDrawElements(DrawModeToGLEnum(mode), numIndices, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    inVertexArray.Unbind();
}