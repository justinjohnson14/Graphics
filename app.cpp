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
#include "GameEngine.h"

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
GameEngine* gameEngine;

std::vector<Object*> objects;

int main(void)
{
    gameEngine = new GameEngine();
    gameEngine->Init();
    gameEngine->Run();
    gameEngine->Shutdown();
}
