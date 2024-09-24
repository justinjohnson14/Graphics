#pragma once

#define MEM_SIZE 1024 * 1024 //1mb

class MemoryManager {
public:
    static void Init();
    static void* Allocate(const int&);
    static void Pop();

    static char* m_memory;
private:
    MemoryManager();
    static int m_stackPointer;
    static int m_basePointer;
};