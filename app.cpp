#include "Log.h"
#include "Object.h"
#include "ResourceManager.h"
#include "Util.h"

#include "Window.h"

#include "Renderer.h"
#include <glad/glad.h>
#include <glm/detail/qualifier.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

void init();
void run();

unsigned int shader(const char*, const char*);
const char* readFile(const char*);
double getCurrentTime();
void update();
static void initLog();


Window* window;
Renderer* renderer;
ResourceManager* rm;
Object* obj1;

const double MS_PER_UPDATE = 1.0f;

int main(void)
{
    window = new Window();
    renderer = new Renderer();
    rm = new ResourceManager();

    init();

    //This needs to be taken care of!!
    obj1 = new Object();

    unsigned int shader1 = 1;
    unsigned int model1 = 2;

    obj1->model = rm->getResource("model1", ResourceManager::ModelResource);
    obj1->model->load("./res/models/Truss/Truss.obj");

    obj1->shader = rm->getResource("shader1", ResourceManager::ShaderResource);
    obj1->shader->load(GL_VERTEX_SHADER, "./res/shaders/vertex.glsl");
    obj1->shader->load(GL_FRAGMENT_SHADER, "./res/shaders/vertex.glsl");
    obj1->shader->compile();

    glm::mat4 m = glm::mat4(glm::translate(glm::mat4(1.0f), glm::vec3(300, 300, 0)));
    glm::mat4 v = glm::mat4(1.0f);
    glm::mat4 p = glm::mat4(1.0f);

    p = glm::ortho(0.0f, (float)window->SCR_WIDTH, (float)window->SCR_HEIGHT, 0.0f);

    unsigned int modelLoc = glGetUniformLocation(obj1->shader->getID(), "model");
    unsigned int viewLoc = glGetUniformLocation(obj1->shader->getID(), "view");
    unsigned int projLoc = glGetUniformLocation(obj1->shader->getID(), "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(v));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(p));

    //glm::mat4 model = glm::mat4(glm::translate(glm::mat4(1.0f), glm::vec3(300, 300, 0)));
    //glm::mat4 view = glm::mat4(1.0f);
    //glm::mat4 projection = glm::mat4(1.0f);

    //model = glm::scale(model, glm::vec3(10.0f, 10.0f, 0.0f));

    //projection = glm::ortho(0.0f, (float)SCR_WIDTH, (float)SCR_HEIGHT,0.0f);

    //unsigned int modelLoc = glGetUniformLocation(shader1->ID, "model");
    //unsigned int viewLoc = glGetUniformLocation(shader1->ID, "view");
    //unsigned int projectionLoc = glGetUniformLocation(shader1->ID, "projection");
    //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    //glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

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
    return;
}

void init()
{
    Log::init();
    window->init();
    renderer->init();
}

void run()
{
    double previous = getCurrentTime();
    double lag = 0.0;
    while (window->running)
    {
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
