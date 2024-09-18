#include "Log.h"
#include "Util.h"

#include "Window.h"

#include "Renderer.h"

void init();
void run();

unsigned int shader(const char*, const char*);
const char* readFile(const char*);
double getCurrentTime();
void update();
static void initLog();


std::unique_ptr<Window> window;
std::unique_ptr<Renderer> renderer;

const double MS_PER_UPDATE = 1.0f;

int main(void)
{
    window = std::make_unique<Window>();
    renderer = std::make_unique<Renderer>();
    init();

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

        window->processInput();

        while(lag >= MS_PER_UPDATE)
        {
            update();
            lag -= MS_PER_UPDATE;
        }

        renderer->Draw();

        window->swapBuffers();
    }
}

void shutdown()
{
    LOG_INFO("Shutting down...");
}
