#pragma once

#include "Model.h"
#include "ResourceManager.h"

#include <glm/glm.hpp>
#include <memory>

class Object {
public:
    Object();
    glm::vec3 transform;
    unsigned int layer;
    unsigned int scene;

    void update();

    std::shared_ptr<Resource> model;
    std::shared_ptr<Resource> shader;
    std::shared_ptr<EventListener> m_eventListener = std::make_shared<EventListener>();
private:
};
