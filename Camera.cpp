#include "Camera.h"

Camera::Camera(Window* window)
    : m_windowHandle(window)
{
    m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));
    m_projection = glm::perspective(glm::radians(45.0f), (float)m_windowHandle->SCR_WIDTH/(float)m_windowHandle->SCR_HEIGHT, 0.1f, 100.0f);
}
