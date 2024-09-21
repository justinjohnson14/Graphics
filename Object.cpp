#include "Object.h"
#include "Shader.h"
#include <glad/glad.h>
#include <vector>

Object::Object()
{
    model = new Model();
    shader = new Shader("./res/shaders/vertex.glsl", "./res/shaders/fragment.glsl");

    model->load("./res/models/backpack/backpack.obj");

    shader->compile();
}

void Object::update()
{
    shader->use();
    model->draw();

    /*
    unsigned int VAO, VBO, EBO;

    float vertices[] = {
        //front
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,

        //back
        0.0f, 0.0f, -0.5f,
        0.5f, 0.0f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.0f, 0.5f, -0.5f,
    };

    unsigned int indicies[] = {
        //front
        0, 1, 2,
        0, 2, 3,

        //right
        1,5,6,
        1,6,2,

        //back
        4,5,6,
        4,6,7,

        //left
        4,0,3,
        4,3,7,

        //top
        3,2,6,
        3,6,7,

        //bottom
        4,5,1,
        4,1,0
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),&vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), &indicies[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);


    glDrawElements(GL_TRIANGLES, sizeof(indicies)/sizeof(indicies[0]), GL_UNSIGNED_INT, 0);

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
    */
}
