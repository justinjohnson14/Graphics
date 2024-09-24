#include "GameEngine.h"

int main()
{
    gameEngine = new GameEngine();
    gameEngine->Init();
    gameEngine->Run();
    gameEngine->Shutdown();
}