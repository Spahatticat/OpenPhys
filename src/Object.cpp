#include "Object.h"

Object::Object(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl)
    : position(pos), rotation(rot), scale(scl), vertices({})
{

}


Object::~Object()
{
}

void Object::update(float deltaTime)
{
    // Update object logic here
}

void Object::render()
{
    // Render object in the world here
}

void Object::setPosition(const glm::vec3& pos)
{
    position = pos;
}

void Object::setRotation(const glm::vec3& rot)
{
    rotation = rot;
}

void Object::setScale(const glm::vec3& scl)
{
    scale = scl;
}

glm::vec3 Object::getPosition() const
{
    return position;
}

glm::vec3 Object::getRotation() const
{
    return rotation;
}

glm::vec3 Object::getScale() const
{
    return scale;
}