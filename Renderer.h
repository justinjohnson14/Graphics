#pragma once

#include <queue>

#include "Shader.h"

class Renderer {
public:
    struct DrawCall{
        Shader* shader = nullptr;
        unsigned int* VAO = nullptr;
        float* VBO = nullptr;
        unsigned int* EBO = nullptr;
        int vertexSize = 0;
        int indexSize = 0;
        int count = 0;
    };

    void init();

    void Draw();
    void NewDrawCall(DrawCall&);
private:
    std::queue<DrawCall*> m_drawQueue;
};
