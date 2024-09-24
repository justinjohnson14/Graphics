include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER ${CPP_COMPILER})

FetchContent_Declare(
    imgui-glfw-glad-glm
    GIT_REPOSITORY https://github.com/cmmw/imgui-glfw-glad-glm.git
)
FetchContent_MakeAvailable(imgui-glfw-glad-glm)

include_directories(./spdlog/include)

add_definitions(-DDEBUG)

add_library(GameEngine)

target_sources(GameEngine PUBLIC
    GameEngine.cpp
    Renderer.cpp
    Memory.cpp
    Model.cpp
    Shader.cpp
    Object.cpp
    Window.cpp
    Log.cpp
    Camera.cpp
    glad/src/glad.c
)

target_link_libraries(
    glad
    imgui
    glm
    GL
    GLU
    Xrandr
    Xi
    X11
    dl
    Xinerama
    Xcursor
    assimp
)

add_subdirectory(demo)


