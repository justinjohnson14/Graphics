#include "Memory.h"

#include <memory>

void MemoryManager::Init()
{
    m_memory = (char*)malloc(MEM_SIZE);
    m_basePointer = 0;
    m_stackPointer = 0;
}

void* MemoryManager::Allocate(const int& size)
{
    void* retval = m_memory + m_stackPointer;
    m_basePointer = m_stackPointer;
    m_stackPointer += size+1;
    return retval;
}

void MemoryManager::Pop()
{
    m_stackPointer = m_basePointer;
}