#ifndef CAMERA_H
#define CAMERA_H

#include <includes.h>

class Camera {
public:
    // Constructor
    Camera() : position(0.0f, 0.0f, 3.0f), front(0.0f, 0.0f, -1.0f),
                          up(0.0f, 1.0f, 0.0f), yaw(0.0f), pitch(0.0f) {}

    // Setters and Getters for Camera Position
    void setPosition(float x, float y, float z) {
        position = glm::vec3(x, y, z);
    }

    glm::vec3 getPosition() const {
        return position;
    }

    // Update Camera Movement based on Input
    void processKeyboard(float deltaTime, GLFWwindow* window) {
        float cameraSpeed = 2.5 * deltaTime; // Adjust this value for desired speed

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            position += front * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            position -= front * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            position -= right * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            position += right * cameraSpeed;
    }

    // Update Camera Pitch and Yaw based on Input
    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) {
        xoffset *= mouseSensitivity; // Adjust this value for desired sensitivity
        yoffset *= mouseSensitivity;

        yaw += xoffset;
        pitch += yoffset;

        if (constrainPitch)
            pitch = glm::clamp(pitch, minPitch, maxPitch);

        updateCameraVectors();
    }

private:
    // Camera Attributes
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;

    // Camera Vectors
    glm::vec3 right;
    glm::vec3 worldUp;

    // Update Camera Front, Right and Up vectors using Yaw and Pitch
    void updateCameraVectors() {
        // Calculate the new front vector
        glm::vec3 forwardVector;
        if (cos(glm::radians(pitch)) != 0.0f) {
            forwardVector.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            forwardVector.y = sin(glm::radians(pitch));
            forwardVector.z = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        } else {
            // Ensure that we are not facing up
            forwardVector.x = 0.0f;
            forwardVector.y = 1.0f;
            forwardVector.z = 0.0f;
        }

        front = glm::normalize(forwardVector);
        // Also re-calculate the Right and Up vector
        right = glm::normalize(glm::cross(front, worldUp));  // Normalize the vectors
        up = glm::normalize(glm::cross(right, front));
    }

    static const float cameraSpeed;
    static const float mouseSensitivity;
    static const float minPitch;
    static const float maxPitch;
};

const float Camera::cameraSpeed = 2.5f; // Adjust this value for desired speed
const float Camera::mouseSensitivity = 0.1f; // Adjust this value for desired sensitivity
const float Camera::minPitch = -89.f;
const float Camera::maxPitch = 89.f;

#endif // CAMERA_H
