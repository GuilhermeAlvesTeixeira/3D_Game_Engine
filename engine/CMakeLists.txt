cmake_minimum_required(VERSION 3.10)

project(Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Arquivos da engine
set(ENGINE_SOURCES
    source/Application.cpp
    source/Engine.cpp
    source/input/InputManager.h
    source/input/InputManager.cpp
    source/graphics/ShaderProgram.h 
    source/graphics/ShaderProgram.cpp
)

# Library da engine
add_library(Engine ${ENGINE_SOURCES})

# Includes da engine
target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_SOURCE_DIR}/include 
)

target_sources(Engine PRIVATE
    ${CMAKE_SOURCE_DIR}/src/glad.c
)

# GLFW (thirdparty - caminho corrigido)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw-3.4
                 ${CMAKE_CURRENT_BINARY_DIR}/glfw_build)

# Include do GLFW
target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw-3.4/include
)

# Link GLFW
target_link_libraries(Engine glfw)