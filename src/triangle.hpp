#ifndef LEARNOPENGL_TRIANGLE_HPP
#define LEARNOPENGL_TRIANGLE_HPP

#include <glad/glad.h>

#include <array>

namespace LearnOpenGL {

constexpr static const char* POLYGON_DEFAULT_GLSLVERT = R"(#version 460 core
layout (location = 0) in vec3 aPos;

void main() {
    gl_Position = vec4(aPos.xyz, 1.0);
}
)";

constexpr static const char* POLYGON_DEFAULT_GLSLFRAG = R"(#version 460 core
out vec4 FragColor;

void main() {
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

struct Polygon {
    std::array<float, 9> vertices;

    GLuint vao = 0;
    GLuint vbo = 0;

    /**
     * @brief Generates new mesh buffers from the defined vertex data and updates the `vao`, and `vbo` values of this polygon.
     * Deletes buffers if any are already defined.
    */
    void CreateNewMeshBuffers();
};

constexpr static Polygon DEFAULT_POLYGON = {
{
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}
};

};

#endif
