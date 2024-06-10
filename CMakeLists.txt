cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER "C:/MinGW/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/mingw64/bin/g++.exe")
set(glfw3_DIR "lib/cmake/glfw3")
project(OpenPhys VERSION 0.1)
link_directories(lib/)
find_package(glfw3 REQUIRED)
set(PROJ_BASE_DIR "${PROJECT_SOURCE_DIR}/..")
include_directories(include)
add_executable(
OpenPhys
src/main.cpp
src/glad.c
)
target_link_libraries(OpenPhys opengl32 glfw3)


