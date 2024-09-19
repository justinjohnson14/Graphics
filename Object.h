#pragma once

#include "Model.h"
#include "ResourceManager.h"
#include "Event.h"

#include <glm/glm.hpp>
#include <memory>

class Object {
public:
    Object();
    glm::vec3 transform;
    unsigned int layer;
    unsigned int scene;

    void update();

    Resource* model;
    Resource* shader;
    EventListener* m_eventListener = new EventListener();
private:
};
