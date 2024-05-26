#ifndef LEARNOPENGL_CALLBACKS_HPP
#define LEARNOPENGL_CALLBACKS_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

/**
 * @brief A collection of default GLFW window callbacks for use in the program demo.
*/
namespace DefaultWindowCallbacks {

void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

};

#endif
