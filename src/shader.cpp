#include "shader.hpp"

#include <iostream>

static void dumpShaderCompileStatus(GLuint shader_id) {
    int  success;
    char infoLog[512];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(shader_id, 512, nullptr, infoLog);
        std::cerr << "-- Error: Shader failed to compile:\n\n" << infoLog << '\n';
    }
}

static void dumpShaderProgramLinkStatus(GLuint program_id) {
    int  success;
    char infoLog[512];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(program_id, 512, NULL, infoLog);
        std::cerr << "-- Error: Shader program failed to link:\n\n" << infoLog << '\n';
    }
}

LearnOpenGL::Shader LearnOpenGL::Shader::CreateShaderFromSources(const char* glslvertsrc, const char* glslfragsrc) {
    auto shader = LearnOpenGL::Shader{};

    GLuint glslvert = glCreateShader(GL_VERTEX_SHADER);
    GLuint glslfrag = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(glslvert, 1, &glslvertsrc, nullptr);
    glCompileShader(glslvert);
    dumpShaderCompileStatus(glslvert);

    glShaderSource(glslfrag, 1, &glslfragsrc, nullptr);
    glCompileShader(glslfrag);
    dumpShaderCompileStatus(glslfrag);

    shader.program_id = glCreateProgram();
    glAttachShader(shader.program_id, glslvert);
    glAttachShader(shader.program_id, glslfrag);
    glLinkProgram(shader.program_id);
    dumpShaderProgramLinkStatus(shader.program_id);

    glDeleteShader(glslvert);
    glDeleteShader(glslfrag);

    return shader;
}
