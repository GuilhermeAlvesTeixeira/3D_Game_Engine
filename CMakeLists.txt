cmake_minimum_required(VERSION 3.10)

project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

# Inclui headers
include_directories(include)

# Arquivos fonte
set(SOURCES
    src/main.cpp
    src/glad.c
)

# Cria executável
add_executable(Game Engine V1 ${SOURCES})

# Link com GLFW e OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(Game Engine V1 glfw OpenGL::GL)