cmake_minimum_required(VERSION 3.10)

project(GameApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

# Adiciona a engine
add_subdirectory(engine)

# Executável principal
add_executable(GameApp
    src/main.cpp
    src/Game.h
    src/Game.cpp
)

# Includes globais (GLAD)
include_directories(engine/source)

# OpenGL
find_package(OpenGL REQUIRED)

include_directories(engine/source)

# Linkagem
target_link_libraries(GameApp
    Engine
    OpenGL::GL
)