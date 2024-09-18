#include "Renderer.h"

void Renderer::init()
{

}

void Renderer::Draw()
{

}


void Renderer::NewDrawCall(DrawCall &dc)
{
    m_drawQueue.push(&dc);
}
