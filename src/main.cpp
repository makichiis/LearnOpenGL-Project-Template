#include <glad/glad.h> // Must be included before glfw3.h to avoid redefintions of OpenGL symbols
#include <GLFW/glfw3.h>

#include "callbacks.hpp"
#include "triangle.hpp"
#include "shader.hpp"

#include <iostream>
#include <cstdlib>

constexpr static int DEFAULT_WINDOW_WIDTH = 800;
constexpr static int DEFAULT_WINDOW_HEIGHT = 600;
constexpr static const char* DEFAULT_WINDOW_TITLE = "LearnOpenGL";
constexpr static GLFWmonitor* USE_WINDOWED_MODE = nullptr;
constexpr static GLFWwindow* NO_SHARE_WINDOW = nullptr;

#define GLAD_LOAD_FAILURE 0

/**
 * @brief Entry point function.
 * @param argc The number of arguments in this program, including the program path.
 * @param argv The arguments passed to this program.
*/
int main(int argc, const char** argv) {
    std::cout << "-- Initializing GLFW...\n";
    int success = glfwInit();
    if (success = GLFW_FALSE) {
        std::cerr << "-- Error: Failed to initialize GLFW.\n";
        return EXIT_FAILURE;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
        DEFAULT_WINDOW_WIDTH, 
        DEFAULT_WINDOW_HEIGHT, 
        DEFAULT_WINDOW_TITLE, 
        USE_WINDOWED_MODE, 
        NO_SHARE_WINDOW
    );
    if (!window) {
        std::cerr << "-- Error: Failed to create GLFW window.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    std::cout << "-- Loading GLAD...\n";
    success = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if (success == GLAD_LOAD_FAILURE) {
        std::cerr << "-- Error: Could not load GLAD.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    std::cout << "-- OpenGL Version: " << glGetString(GL_VERSION) << '\n';

    glfwSetFramebufferSizeCallback(window, DefaultWindowCallbacks::FramebufferSizeCallback);
    glfwSetKeyCallback(window, DefaultWindowCallbacks::KeyCallback);

    using namespace LearnOpenGL;
    auto triangle = DEFAULT_POLYGON;
    triangle.CreateNewMeshBuffers();

    auto triangle_shader = Shader::CreateShaderFromSources(POLYGON_DEFAULT_GLSLVERT, POLYGON_DEFAULT_GLSLFRAG);

    while (not glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(triangle_shader.program_id);
        glBindVertexArray(triangle.vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);
        glUseProgram(0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
