#include "Log.h"
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
#include <memory>
#include <vector>

void init();
void run();

unsigned int shader(const char*, const char*);
const char* readFile(const char*);
double getCurrentTime();
void update();
static void initLog();


Window* window;
Renderer* renderer;
Object* obj1;

const double MS_PER_UPDATE = 1.0f;

int main(void)
{
    window = new Window();
    renderer = new Renderer();

    init();

    obj1 = new Object();

    glm::mat4 m = glm::mat4(1.0f);
    glm::mat4 v = glm::mat4(1.0f);
    glm::mat4 p = glm::mat4(1.0f);

    obj1->shader->use();
    std::vector<glm::vec4> test;
    m = glm::rotate(m, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    v = glm::translate(v, glm::vec3(0.0f, 0.0f, -5.0f));
    p = glm::perspective(glm::radians(45.0f), (float)window->SCR_WIDTH/(float)window->SCR_HEIGHT, 0.1f, 100.0f);
    /*
    for(auto i : obj1->model->meshes)
    {
        for(auto j : i.vertices)
        {
            test.push_back(p*v*m*glm::vec4(j.position, 1.0f));
        }
    }

    for(auto i : test)
    {
        LOG_INFO("{0}, {1}, {2}, {3}", i[0], i[1], i[2], i[3]);
    }
    */

    unsigned int modelLoc = glGetUniformLocation(obj1->shader->getID(), "model");
    unsigned int viewLoc = glGetUniformLocation(obj1->shader->getID(), "view");
    unsigned int projLoc = glGetUniformLocation(obj1->shader->getID(), "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(v));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(p));

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    run();
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
    obj1->update();
    return;
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
        renderer->Draw();

        window->swapBuffers();
    }
}

void shutdown()
{
    LOG_INFO("Shutting down...");
}
