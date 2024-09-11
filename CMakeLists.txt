include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(app)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
    imgui-glfw-glad-glm
    GIT_REPOSITORY https://github.com/cmmw/imgui-glfw-glad-glm.git
)
FetchContent_MakeAvailable(imgui-glfw-glad-glm)

add_executable(app app.cpp Shader.cpp glad/src/glad.c)

target_link_libraries(
    app
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
)