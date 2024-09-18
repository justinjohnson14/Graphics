#pragma once
#include "ResourceManager.h"

#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>

#include <string>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indicies;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::vector<Texture>);
    void Draw();
private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

class Model : public Resource{
public:
    Model();
    Model(const std::string&);
    void load() override;
    void load(const std::string&) override;
    void processNode(aiNode*,const aiScene*);
    Mesh processMesh(aiMesh*, const aiScene*);

    std::vector<Mesh> meshes;
};
