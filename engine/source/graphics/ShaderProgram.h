#pragma once
#include <glad/glad.h>
#include <string>
#include <unordered_map>

/* The class represents a shader program that has already been compiled and linked by OpenGL. */

namespace eng {
    class ShaderProgram {

        public:
            ShaderProgram() = delete;
            ShaderProgram(const ShaderProgram&) = delete;
            ShaderProgram& operator = (const ShaderProgram&)= delete;
            explicit ShaderProgram(GLuint shaderProgramID); // construtor real
            ~ShaderProgram();

            void Bind();
            GLint GetUniformLocation(const std::string& name);
            void SetUniform(const std::string& name, float value);

        private:
            std::unordered_map<std::string, GLint> m_uniformLocationCache;
            GLuint m_ShaderProgramID = 0;
    };
}