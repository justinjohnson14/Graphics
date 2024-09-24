#include "Object.h"
#include "Camera.h"
#include "Shader.h"
#include <glad/glad.h>

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Object::Object()
{
    //m_lightPosition = glm::vec3(1.2f, 1.0f, 2.0f);
    //m_lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    //m_objectColor = glm::vec3(0.0f, 0.52f, 0.15f);

    //unsigned int lightPos = glGetUniformLocation(shader->getID(), "lightPos");
    //unsigned int lightColor = glGetUniformLocation(shader->getID(), "lightColor");
    //unsigned int objColor = glGetUniformLocation(shader->getID(), "objectColor");

    //glUniform3fv(lightPos, 1, glm::value_ptr(m_lightPosition));
    //glUniform3fv(lightColor, 1, glm::value_ptr(m_lightColor));
    //glUniform3fv(objColor, 1, glm::value_ptr(m_objectColor));
}

Object::~Object()
{
    glDeleteShader(shader->ID);
    if(model != nullptr)
        delete model;
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
    model->Draw();
}
