#pragma once

#include "Model.h"
#include "ResourceManager.h"

#include <glm/glm.hpp>
#include <memory>

class Object {
public:
    glm::vec3 transform;
    unsigned int layer;
    unsigned int scene;

    std::shared_ptr<Resource> model;
    std::shared_ptr<Resource> shader;
private:
};
