#ifndef LEARNOPENGL_SHADER_HPP
#define LEARNOPENGL_SHADER_HPP

#include <glad/glad.h>

namespace LearnOpenGL {

struct Shader {
    GLuint program_id;

    static Shader CreateShaderFromSources(const char* glslvertsrc, const char* glslfragsrc);
};

}

#endif
