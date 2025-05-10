# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(OpenPhys VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Add the executable
add_executable(OpenPhys src/main.cpp)

# Include directories (if needed)
# target_include_directories(OpenPhys PRIVATE include)

# Link libraries (if needed)
# target_link_libraries(OpenPhys PRIVATE some_library)

set(glfw3_DIR "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")
find_package(glfw3 REQUIRED)
# Find and include GLFW
target_link_libraries(OpenPhys PRIVATE glfw)