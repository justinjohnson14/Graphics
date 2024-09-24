#include "GameEngine.h"

GameEngine::GameEngine()
{
    m_window = new Window();
    m_renderer = new Renderer();

    m_objects.push_back(new Object());
    m_objects.push_back(new Object());
    m_camera = new Camera(m_window);

    for(auto i : m_objects)
    {
        i->shader = new Shader("./res/shaders/vertex.glsl", "./res/shaders/fragment.glsl");
        i->shader->compile();
    }

    m_objects[0]->model = new Model(ShapeType::Circle);
    m_objects[1]->model = new Model(ShapeType::Rectangle);

    m_objects[0]->m_position = glm::vec3(-2.0f, 10.0f, 10.0f);
    m_objects[1]->m_position = glm::vec3(-100.0f, -10.0f, 10.0f);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void GameEngine::Init()
{
    Log::init();
    window->init();
    renderer->init();
    //glEnable(GL_DEPTH_TEST);
}

void GameEngine::Run()
{
    m_previous = getCurrentTime();
    m_lag = 0.0;
    objects[1]->m_force = glm::vec3(50.0f, 0.0f, 0.0f);
    while (window->running)
    {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        double current = getCurrentTime();
        double elapsed = current - m_previous;
        m_previous = current;
        m_lag += elapsed;

        while(m_lag >= MS_PER_UPDATE)
        {
            update();
            m_lag -= MS_PER_UPDATE;
        }
        for(auto i : objects)
        {
            i->draw(camera);
        }

        window->swapBuffers();
    }
}

void GameEngine::Update()
{
    for(auto i : objects)
    {
        i->update();
    }
}

void GameEngine::Shutdown()
{
    for(auto i : objects)
    {
        delete i;
    }
    LOG_INFO("Shutting down...");
}

double GameEngine::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}