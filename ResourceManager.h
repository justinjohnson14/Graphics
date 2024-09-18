#pragma once
#include <glad/glad.h>
#include <map>
#include <memory>


class Resource {
public:
    virtual ~Resource();
    virtual void load() = 0;
    virtual void load(const GLenum&, const std::string&) = 0;
    virtual void load(const std::string&) = 0;
private:
};

class ResourceManager {
public:
    enum resourceType {
        NoneResource,
        ModelResource,
        ShaderResource,
    };

    std::map<std::string, std::shared_ptr<Resource>> loadedResources;
    std::map<std::string, unsigned int> instanceCount;

    std::shared_ptr<Resource> getResource(const std::string&, const resourceType&);
private:
};
