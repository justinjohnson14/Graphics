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
Object* obj1, *obj2;
Camera* camera;

int main(void)
{
    window = new Window();
    renderer = new Renderer();

    init();

    //obj1 = new Object();
    obj2 = new Object();
    camera = new Camera(window);

    //obj1->model = new Model("./res/models/backpack/backpack.obj");
    obj2->model = new Model();
    obj2->model->GenCircle(1.0f);

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
    //obj1->update();
    obj2->update();
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
    //obj1->m_force = glm::vec3(1.0f, 0.0f, 0.0f);
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
        //obj1->shader->use();
        //obj1->model->draw();
        //obj1->draw(camera);
        obj2->draw(camera);

        window->swapBuffers();
    }
}

void shutdown()
{
    delete obj1;
    delete obj2;
    LOG_INFO("Shutting down...");
}
