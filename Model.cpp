#include "Model.h"
#include "Log.h"

#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <cmath>
#include <cstddef>
#include <glad/glad.h>
#include <glm/ext/vector_float2.hpp>
#include <string>
#include <vector>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int>indicies, std::vector<Texture> textures) :
    vertices(vertices), indicies(indicies), textures(textures)
{
    Mesh::SetupMesh();
}

void Mesh::SetupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex),&vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(unsigned int), &indicies[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}

void Mesh::Draw()
{
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indicies.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
}

Model::Model()
{

}

void Model::Draw()
{
    for(unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].Draw();
}

void Model::Load(const std::string& file)
{
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        LOG_ERROR("Error importing scene: {}", file);


    ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(ProcessMesh(mesh, scene));
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        ProcessNode(node->mChildren[i], scene);
    }
}

Mesh Model::ProcessMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indicies;
    std::vector<Texture> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.normal = vector;

        if(mesh->mTextureCoords[0])
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoords = vec;
        }else {
            vertex.texCoords = glm::vec2(0.0f, 0.0f);
        }
        vertices.push_back(vertex);
    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indicies.push_back(face.mIndices[j]);
    }

    return Mesh(vertices, indicies, textures);
}

void Model::GenCircle(float radius)
{
    float angle = std::asinf(0.1 / (2*radius)) * 2;
    angle = std::fminf(angle, M_PI - (M_PI * 0.95f));

    const float steps = (M_PI*2) / angle;

    int segmentCount = (int)std::ceilf(steps);
    segmentCount = (segmentCount < 3) ? 3 : segmentCount;

    const int vertexCount = 1 + segmentCount;
    const int faceCount = segmentCount;
    const int indexCount = faceCount*3;

    std::vector<Vertex> vertices;
    Vertex v0;
    v0.position = glm::vec3(0.0f, 0.0f, 0.0f);
    vertices.push_back(v0);

    const float angleStep = (M_PI*2) / segmentCount;

    for(int i = 0; i < segmentCount; ++i)
    {
        const float angle0 = angleStep*i;
        const float x = std::cosf(angle0);
        const float y = std::sinf(angle0);

        const float pos_x = 0.0 + x * radius;
        const float pos_y = 0.0 + y * radius;

        Vertex vertex;
        vertex.position = glm::vec3(pos_x, pos_y, 0.0f);
        vertices.push_back(vertex);
    }

    std::vector<unsigned int> indicies;
    for (int i = 0; i < segmentCount; i++)
    {
        indicies.push_back(0);
        indicies.push_back(i+1);
        indicies.push_back(1+((i + 1) % segmentCount));
    }

    std::vector<Texture> tex;
    
    meshes.push_back(Mesh(vertices, indicies, tex));
}
