cmake_minimum_required(VERSION 3.10)

project(GameApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona a engine
add_subdirectory(engine)

# Executável principal
add_executable(GameApp
    src/main.cpp
    src/glad.c
)

# Includes globais (GLAD)
target_include_directories(GameApp PRIVATE include)

# OpenGL
find_package(OpenGL REQUIRED)

# Linkagem
target_link_libraries(GameApp
    Engine
    OpenGL::GL
)