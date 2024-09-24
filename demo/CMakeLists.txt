include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(DemoApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER ${CPP_COMPILER})

FetchContent_Declare(
    imgui-glfw-glad-glm
    GIT_REPOSITORY https://github.com/cmmw/imgui-glfw-glad-glm.git
)
FetchContent_MakeAvailable(imgui-glfw-glad-glm)

include_directories(
    ../spdlog/include
    ../include/
    )

add_definitions(-DDEBUG)

add_executable(DemoApp)
target_sources(DemoApp PUBLIC
    DemoApp.cpp
)

target_link_libraries(
    GameEngine
)
