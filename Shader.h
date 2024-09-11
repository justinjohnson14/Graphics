class Shader {
public:
    Shader();
    Shader(std::string, std::string);

    unsigned int setShader(const GLuint&, const std::string&);

    const std::string read(const std::string&);

    unsigned int compile();

    void use();

    unsigned int ID;
private:
    const char *  m_vertexSrc;
    const char * m_geometrySrc;
    const char * m_fragmentSrc;
    const char * m_ComputeSrc;
    unsigned int m_vertexID, m_geometryID, m_fragmentID, m_computeID;
};