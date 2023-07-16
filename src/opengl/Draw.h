//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_DRAW_H
#define ANIMATIONPROGRAMMING_DRAW_H

#include "IndexBuffer.h"
#include "VertexArray.h"

enum class DrawMode {
    Points,
    LineStrip,
    LineLoop,
    Lines,
    Triangles,
    TriangleStrip,
    TriangleFan
};

namespace Anim {
    void Draw(IndexBuffer& inIndexBuffer, VertexArray& inVertexArray, DrawMode mode);
    void Draw(unsigned int vertexCount, VertexArray& inVertexArray, DrawMode mode);
}

#endif //ANIMATIONPROGRAMMING_DRAW_H
