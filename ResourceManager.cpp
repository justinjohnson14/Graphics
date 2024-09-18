#include "ResourceManager.h"

#include "Model.h"
#include "Shader.h"

#include <memory>

std::shared_ptr<Resource> ResourceManager::getResource(const unsigned int& res, const resourceType& resType)
{
    if(loadedResources.count(res))
    {
        return loadedResources.at(res);
    }

    std::shared_ptr<Resource> ptr;
    switch (resType) {
    case ModelResource:
        ptr = std::make_shared<Model>();
    case ShaderResource:
        ptr = std::make_shared<Shader>();
    default:
        ptr = nullptr;
    }

    loadedResources.insert({res,ptr});

    return ptr;
}
