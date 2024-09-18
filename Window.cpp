#include "Window.h"
#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <cstddef>
#include <iostream>

void Window::init()
{
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_windowHandle = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Game Engine", NULL, NULL);

    if(!m_windowHandle)
    {
        std::cerr << "Failed to create window!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_windowHandle);
    glfwSetFramebufferSizeCallback(m_windowHandle, framebuffer_size_callback);
    gladLoadGL();
}

void Window::processInput()
{
    if(glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        running = false;
}

void Window::swapBuffers()
{
    glfwPollEvents();
    glfwSwapBuffers(m_windowHandle);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}
