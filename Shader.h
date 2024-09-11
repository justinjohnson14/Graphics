#pragma once

#include <glad/glad.h>

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

class Shader {
public:
    Shader();
    Shader(std::string, std::string);

    void setShader(const GLuint&, const std::string&);

    void compile();

    void use();

    unsigned int ID;
private:
    unsigned int m_vertexID, m_tesselationID, m_geometryID, m_fragmentID, m_computeID;
    std::string read(const std::string&);
};