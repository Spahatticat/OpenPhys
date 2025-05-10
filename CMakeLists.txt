cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_C_COMPILER "gcc.exe")
set(CMAKE_CXX_COMPILER "g++.exe")
set(PROJECT_SOURCE_DIR ../src)
set(glfw3_DIR "lib/cmake/glfw3")
project(OpenPhys VERSION 0.1)
link_directories(lib/)
find_package(glfw3 REQUIRED)
include_directories(OpenPhys include)
add_executable(
OpenPhys
src/main.cpp
src/glad.c
src/object.cpp
)
target_link_libraries(OpenPhys opengl32 glfw3)


