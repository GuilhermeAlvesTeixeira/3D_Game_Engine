cmake_minimum_required(VERSION 3.10)

project(Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Arquivos da engine
set(ENGINE_SOURCES
    source/Application.cpp
    source/Engine.cpp
)

# Library da engine
add_library(Engine ${ENGINE_SOURCES})

# Includes da engine
target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/source
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