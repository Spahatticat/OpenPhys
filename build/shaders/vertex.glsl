#version 330 core
layout(location = 0) in vec2 vertexPos; // Vertex position

out vec3 fragColor; // Output to fragment shader

void main() {
    // Set the position of the vertex
    gl_Position = vec4(vertexPos, 0.0, 1.0);
    
    // Pass the color to the fragment shader
}