#pragma once

#include "ResourceManager.h"

#include <glad/glad.h>

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

class Shader : public Resource{
public:
    Shader();
    Shader(const std::string&, const std::string&);

    void load(const GLuint&, const std::string&) override;

    void load() override;

    void compile();

    void use();

    unsigned int ID;
private:
    unsigned int m_vertexID, m_tesselationID, m_geometryID, m_fragmentID, m_computeID;
    std::string read(const std::string&);
};
