#include "Shader.h"
#include <queue>

class Renderer {
public:
    struct DrawCall{
        Shader* shader = nullptr;
        unsigned int* layout = nullptr;
        float* vertex = nullptr;
        unsigned int* index = nullptr;
        int vertexSize = 0;
        int indexSize = 0;
    };

    void Draw();
    void NewDrawCall(DrawCall&);
private:
    std::queue<DrawCall*> m_drawQueue;
};


void Renderer::Draw()
{
    for(; !m_drawQueue.empty(); m_drawQueue.pop())
    {
        
    }
}


void Renderer::NewDrawCall(DrawCall &dc)
{
    m_drawQueue.push(&dc);
}