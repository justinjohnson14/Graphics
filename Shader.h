#pragma once

#include <glad/glad.h>

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

class Shader{
public:
    Shader(const std::string&, const std::string&);


    void load(const GLuint&, const std::string&);

    unsigned int getID() {return ID;}

    void compile();

    void use();

    unsigned int ID;
private:
    unsigned int m_vertexID, m_tesselationID, m_geometryID, m_fragmentID, m_computeID;
    std::string read(const std::string&);
};
