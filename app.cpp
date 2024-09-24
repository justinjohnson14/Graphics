#include "Log.h"
#include "Model.h"
#include "Object.h"
#include "Util.h"

#include "Window.h"

#include "Renderer.h"
#include <glad/glad.h>
#include <glm/detail/qualifier.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <vector>
#include "Camera.h"

void init();
void run();
void shutdown();

unsigned int shader(const char*, const char*);
const char* readFile(const char*);
double getCurrentTime();
void update();
static void initLog();


Window* window;
Renderer* renderer;
Camera* camera;

std::vector<Object*> objects;

int main(void)
{
    window = new Window();
    renderer = new Renderer();

    init();

    objects.push_back(new Object());
    objects.push_back(new Object());
    camera = new Camera(window);

    for(auto i : objects)
    {
        i->shader = new Shader("./res/shaders/vertex.glsl", "./res/shaders/fragment.glsl");
        i->shader->compile();
    }

    objects[0]->model = new Model(ShapeType::Circle);
    objects[1]->model = new Model(ShapeType::Rectangle);

    objects[0]->m_position = glm::vec3(-2.0f, 10.0f, 10.0f);
    objects[1]->m_position = glm::vec3(-100.0f, -10.0f, 10.0f);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    run();
    shutdown();
    return 0;
}

double getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void update()
{
    for(auto i : objects)
    {
        i->update();
    }
}

void init()
{
    Log::init();
    window->init();
    renderer->init();
    glEnable(GL_DEPTH_TEST);
}

void run()
{
    double previous = getCurrentTime();
    double lag = 0.0;
    objects[1]->m_force = glm::vec3(50.0f, 0.0f, 0.0f);
    while (window->running)
    {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        while(lag >= MS_PER_UPDATE)
        {
            update();
            lag -= MS_PER_UPDATE;
        }
        for(auto i : objects)
        {
            i->draw(camera);
        }

        window->swapBuffers();
    }
}

void shutdown()
{
    for(auto i : objects)
    {
        delete i;
    }
    LOG_INFO("Shutting down...");
}
