#include "ResourceManager.h"

#include "Model.h"
#include "Shader.h"

#include <memory>

std::shared_ptr<Resource> ResourceManager::getResource(const std::string& file, const resourceType& res)
{
    if(loadedResources.count(file))
    {
        return loadedResources.at(file);
    }

    std::shared_ptr<Resource> ptr;
    switch (res) {
    case ModelResource:
        ptr = std::make_shared<Model>();
    case ShaderResource:
        ptr = std::make_shared<Shader>();
    default:
        ptr = nullptr;
    }

    loadedResources.insert({file,ptr});

    return ptr;
}
