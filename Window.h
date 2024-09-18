#pragma once

#include "Util.h"

class Window {
public:
    static void framebuffer_size_callback(GLFWwindow*, int,int);
    void processInput();

    void init();

    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 800;

    bool running = true;

    void swapBuffers();
private:
    GLFWwindow* m_windowHandle;
};
