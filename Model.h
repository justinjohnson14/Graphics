#pragma once

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

enum ShapeType {
    Circle,
    Ellipse,
    Square,
    Rectangle,
    Triangle,
    Rhombus,
    Trapezium,
    Pentagone,
    Hexagone,
    Octagon,
    Cylinder,
    Cone,
    Cube,
    RectangularPrism,
    Pyramid,
    Sphere
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indicies;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::vector<Texture>);
    void draw();
private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

class Model{
public:
    Model(const std::string& file){load(file);}
    Model(const ShapeType&);
    void load(const std::string&);
    void processNode(aiNode*,const aiScene*);
    Mesh processMesh(aiMesh*, const aiScene*);
    void draw();

    std::vector<Mesh> meshes;
};
