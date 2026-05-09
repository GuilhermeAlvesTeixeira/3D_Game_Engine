#pragma once
#include <glad/glad.h>
#include <memory>
#include <string>

// The graphics API centralizes rendering operations.

namespace eng {

    class ShaderProgram;
    class GraphicsAPI {

        public:
            std::shared_ptr<ShaderProgram> CreateShaderProgram(const std::string& vertexSource, 
                                                               const std::string& fragmentSource);
        
            void BindShaderProgram(ShaderProgram* ShaderProgram);
    };
}