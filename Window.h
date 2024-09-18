#pragma once

#include "Util.h"

class Window {
public:
    static void framebuffer_size_callback(GLFWwindow*, int,int);
    static void key_callback(GLFWwindow*, int, int, int);
    void Window::cursor_pos_callback(GLFWwindow*, double, double)

    void init();

    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 800;

    bool running = true;

    void swapBuffers();
private:
    GLFWwindow* m_windowHandle;
};
