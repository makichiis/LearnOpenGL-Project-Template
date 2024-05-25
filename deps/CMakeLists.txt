cmake_minimum_required(VERSION 3.20)
project(Deps)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("libs/glm")
add_subdirectory("libs/glfw")
add_subdirectory("libs/glad")

# include_directories("libs/glm")
# include_directories("libs/glfw/include")
# include_directories("libs/glad/include")
