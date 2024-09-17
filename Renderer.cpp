#include "Shader.h"
#include <queue>

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

    void Draw();
    void NewDrawCall(DrawCall&);
private:
    std::queue<DrawCall*> m_drawQueue;
};


void Renderer::Draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        model = glm::translate(model, glm::vec3(0.1f, 0.0f, 0.0f));

        shader1->use();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        glBindVertexArray(circle.VAO);
        glDrawElements(GL_TRIANGLES, circle.count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers();
    for(; !m_drawQueue.empty(); m_drawQueue.pop())
    {
        DrawCall draw = m_drawQueue.front();
        glBindVertexArray(&draw.VAO);
        glDrawElements(GL_TRIANGLES, draw.count, GL_UNSIGNED_INT, 0);
    }
}


void Renderer::NewDrawCall(DrawCall &dc)
{
    m_drawQueue.push(&dc);
}