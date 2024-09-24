#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Object.h"

#define MS_PER_UPDATE 1.0f

class GameEngine {
public:
    void Init();
    void Run();
    void Update();
    void Shutdown();

    Window* m_window;
    Renderer* m_renderer;
    std::vector<Object*> m_objects;
    Camera* m_camera;
    double m_previous;
    double m_lag;
    double m_current;
    double m_elapsed;
private:
};