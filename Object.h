#pragma once

#include "Model.h"
#include "Event.h"
#include "Shader.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <memory>
#include <pthread.h>

class Transform{
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};

class Object {
public:
    Object();
    ~Object();
    Transform* transform;
    unsigned int layer;
    unsigned int scene;

    void update();
    void draw(Camera*);

    Model* model;
    Shader* shader;

    glm::mat4 m_model = glm::mat4(1.0f);

    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_force;
    float m_mass = 0.5f;

    glm::vec3 m_lightPosition;
    glm::vec3 m_lightColor;
    glm::vec3 m_objectColor;

    //std::vector<Component*> components;
private:
};
