#include "ResourceManager.h"

#include "Model.h"
#include "Shader.h"

Resource* ResourceManager::getResource(const std::string& res, const resourceType& resType)
{
    if(loadedResources.count(res))
    {
        return loadedResources.at(res);
    }

    Resource* ptr;
    switch (resType) {
    case ModelResource:
        ptr = new Model();
    case ShaderResource:
        ptr = new Shader();
    default:
        ptr = nullptr;
    }

    loadedResources.insert({res,ptr});

    return ptr;
}
