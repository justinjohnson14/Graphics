#include <glad/glad.h>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

#include "Shader.h"

Shader::Shader(std::string vs, std::string fs)
{
    this->setShader(GL_VERTEX_SHADER, vs);
    this->setShader(GL_FRAGMENT_SHADER, fs);
}

unsigned int Shader::setShader(const GLuint& type, const std::string& file)
{

    switch (type) {
        case GL_VERTEX_SHADER:
            m_vertexSrc = read(file).c_str();
            m_vertexID = glCreateShader(type);
            glShaderSource(m_vertexID, 1, &m_vertexSrc, NULL);
            glCompileShader(m_vertexID);
        case GL_FRAGMENT_SHADER:
            m_fragmentSrc = read(file).c_str();
            m_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(m_fragmentID, 1, &m_fragmentSrc, NULL);
            glCompileShader(m_fragmentID);
    }

    GLint succsess;
    glGetShaderiv(m_vertexID, GL_COMPILE_STATUS, &succsess);
    if(!succsess)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_vertexID, 512, NULL, infoLog);
        fprintf(stderr, "Shader compilation error: \n%s\n", infoLog);
        glDeleteShader(m_vertexID);
        return -1;
    }

    return 0;
}

const std::string Shader::read(const std::string& src)
{
    std::ifstream file(src);

    // confirm file opening
    if (!file.is_open()) {
        // print error message and return
        std::cerr << "Failed to open file: " << src << std::endl;
        return 0;
    }

    // Read the file line by line into a string
    std::stringstream buffer;
    buffer << file.rdbuf();

    // Close the file
    file.close();

    return buffer.str();
}

unsigned int Shader::compile()
{
    ID = glCreateProgram();
    glAttachShader(ID, m_vertexID);
    glAttachShader(ID, m_fragmentID);
    glLinkProgram(ID);
}

void Shader::use()
{
    glUseProgram(ID);
}
