#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.h"

class Camera {
public:
    Camera(Window*);

    glm::mat4 m_view;
    glm::mat4 m_projection;

    Window* m_windowHandle;
};
