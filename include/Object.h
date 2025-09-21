#include <includes.h>

class Object
{
public:
    Object(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl);
    ~Object();

    void update(float deltaTime);
    void render();

    void setPosition(const glm::vec3& pos);
    void setRotation(const glm::vec3& rot);
    void setScale(const glm::vec3& scl);

    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale() const;

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 modelMatrix;

    // The Object's vertext data is formated as follows:
    // position (3 floats), texture coordinates (3 floats) per vertex
    std::vector<float> vertices;
    unsigned int VBO, VAO;
};