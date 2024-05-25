cmake_minimum_required(VERSION 3.20)
project("opengl_triangle")

add_subdirectory("deps/")

set(CMAKE_VERBOSE_MAKEFILE OFF) # set to ON to see what cmake is calling, if you really want to know.

set(CMAKE_CXX_STANDARD 20) # set this to whatever version of the C++ standard you want to use
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*")
add_executable("opengl_triangle" ${SOURCES})

target_include_directories("opengl_triangle" PRIVATE "deps/libs/glm") 
target_include_directories("opengl_triangle" PRIVATE "deps/libs/glfw/include") 
target_include_directories("opengl_triangle" PRIVATE "deps/libs/glad/include") 

target_link_directories("opengl_triangle" PRIVATE "${CMAKE_BINARY_DIR}/deps/libs/glfw/src")
target_link_directories("opengl_triangle" PRIVATE "${CMAKE_BINARY_DIR}/deps/libs/glm/glm")
target_link_directories("opengl_triangle" PRIVATE "${CMAKE_BINARY_DIR}/deps/libs/glad")

target_link_libraries("opengl_triangle" PRIVATE glm glfw3 glad)
