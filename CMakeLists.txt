# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(OpenPhys VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
add_executable(OpenPhys src/main.cpp src/glad.c)

set(glfw3_DIR "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")
find_package(glfw3 REQUIRED)
target_include_directories(OpenPhys PRIVATE include) 
target_link_libraries(OpenPhys glfw opengl32)