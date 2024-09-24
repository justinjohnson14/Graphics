include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(DemoApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER ${CPP_COMPILER})

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
