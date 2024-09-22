#include "Shader.h"
#include "Log.h"
#include <glad/glad.h>
#include <string>

Shader::Shader(const std::string& vs, const std::string& fs)
{
    load(GL_VERTEX_SHADER, vs);
    load(GL_FRAGMENT_SHADER, fs);
}

void Shader::load(const GLuint& type, const std::string& file)
{
    std::string* src = new std::string(read(file));
    const char* c_src= src->c_str();
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &c_src, NULL);
    glCompileShader(shader);

    GLint succsess;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &succsess);
    if(!succsess)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        fprintf(stderr, "Shader compilation error: \n%s\n", infoLog);
        LOG_WARN("Shader compilation error: {}", infoLog);
        glDeleteShader(shader);
        return;
    }

    switch (type)
    {
    case GL_VERTEX_SHADER:
        m_vertexID = shader;
    case GL_TESS_CONTROL_SHADER:
        m_tesselationID = shader;
    case GL_GEOMETRY_SHADER:
        m_geometryID = shader;
    case GL_FRAGMENT_SHADER:
        m_fragmentID = shader;
    case GL_COMPUTE_SHADER:
        m_computeID = shader;
    }
    return;
}

std::string Shader::read(const std::string& src)
{
    std::ifstream file(src);

    // confirm file opening
    if (!file.is_open()) {
        // print error message and return
        std::cerr << "Failed to open file: " << src << std::endl;
        LOG_ERROR("Failed to open file: {}", src);
        return 0;
    }

    // Read the file line by line into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    //std::cout << buffer.str() << std::endl;

    // Close the file
    file.close();

    return buffer.str();
}

void Shader::compile()
{
    ID = glCreateProgram();
    glUseProgram(ID);
    glAttachShader(ID, m_vertexID);
    glAttachShader(ID, m_fragmentID);
    glLinkProgram(ID);
    GLint succsess;
    glGetProgramiv(ID, GL_LINK_STATUS, &succsess);
    if(!succsess)
    {
        char infoLog[512];
        glGetShaderInfoLog(ID, 512, NULL, infoLog);
        fprintf(stderr, "Shader link error: \n%s\n", infoLog);
        LOG_WARN("Shader compilation error: {}", infoLog);
        glDeleteShader(ID);
        return;
    }
    glUseProgram(0);
    return;
}

void Shader::use()
{
    glUseProgram(ID);
}
