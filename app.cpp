#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <math.h>

#include "Shader.h"
#include "Renderer.h"

struct circleData {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int count;
};

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
unsigned int shader(const char*, const char*);
const char* readFile(const char*);
double getCurrentTime();
void update();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const double MS_PER_UPDATE = 1.0f;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    gladLoadGL();

    Renderer* renderer = new Renderer();

    Shader* shader1 = new Shader("./res/vertex.glsl", "./res/fragment.glsl");
    shader1->compile();

    shader1->use();

    glm::mat4 model = glm::mat4(glm::translate(glm::mat4(1.0f), glm::vec3(300, 300, 0)));
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::scale(model, glm::vec3(10.0f, 10.0f, 0.0f));
    
    projection = glm::ortho(0.0f, (float)SCR_WIDTH, (float)SCR_HEIGHT,0.0f);

    unsigned int modelLoc = glGetUniformLocation(shader1->ID, "model");
    unsigned int viewLoc = glGetUniformLocation(shader1->ID, "view");
    unsigned int projectionLoc = glGetUniformLocation(shader1->ID, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    double previous = getCurrentTime();
    double lag = 0.0;
    
    while (!glfwWindowShouldClose(window))
    {
        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        processInput(window);

        while(lag >= MS_PER_UPDATE)
        {
            update();
            lag -= MS_PER_UPDATE;
        }

        renderer->Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteProgram(shader1->ID);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void drawDisk(float x, float y, float theta, float radius)
{
    
}

double getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void update()
{
    return;
}