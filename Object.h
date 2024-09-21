#pragma once

#include "Model.h"
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

    Model* model;
    //Resource* shader;
private:
};
