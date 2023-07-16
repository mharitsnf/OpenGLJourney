#version 330 core

// Uniform we are getting from the CPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Data from OpenGL buffers
in vec3 position;
in vec3 normal;
in vec2 texCoord;

// Outputs for fragment shader
out vec3 norm;
out vec3 fragPos;
out vec2 uv;

void main() {
    // Remember that OpenGL operations works right to left,
    // meaning calculating MVP matrix works from projection -> view -> model
    gl_Position = projection * view * model * vec4(position, 1.0);

    fragPos = vec3(model * vec4(position, 1.0));
    norm = vec3(model * vec4(normal, 0.0f));
    uv = texCoord;
}