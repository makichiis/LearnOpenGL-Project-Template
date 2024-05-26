#include "triangle.hpp"

void LearnOpenGL::Polygon::CreateNewMeshBuffers() {
    if (vao != 0 || vbo != 0) {
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
}
