#include "Object.h"
#include "Camera.h"
#include "Shader.h"
#include <glad/glad.h>

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Object::Object()
{
    shader = new Shader("./res/shaders/vertex.glsl", "./res/shaders/fragment.glsl");
    shader->compile();
}

void Object::update()
{
    m_position = m_velocity * 0.001f;
    m_velocity = m_acceleration * 0.001f;
    m_acceleration = m_force / m_mass;
    m_model = glm::translate(m_model, m_position);
}

void Object::draw(Camera* camera)
{
    shader->use();
    unsigned int modelLoc = glGetUniformLocation(shader->getID(), "model");
    unsigned int viewLoc = glGetUniformLocation(shader->getID(), "view");
    unsigned int projLoc = glGetUniformLocation(shader->getID(), "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m_model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->m_view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->m_projection));
    model->draw();
}
