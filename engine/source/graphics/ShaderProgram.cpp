#include "graphics/ShaderProgram.h"

namespace eng {

    ShaderProgram::ShaderProgram(GLuint shaderProgramID) : m_ShaderProgramID(shaderProgramID) {
        
    }

    ShaderProgram::~ShaderProgram(){
        glDeleteProgram(m_ShaderProgramID);
    }

    void ShaderProgram::Bind() {
        glUseProgram(m_ShaderProgramID);
    }

    GLint ShaderProgram::GetUniformLocation(const std::string& name){
        auto it = m_uniformLocationCache.find(name);

        if(it != m_uniformLocationCache.end()) {
            return it->second;
        }
        GLint location = glGetUniformLocation(m_ShaderProgramID, name.c_str());
        m_uniformLocationCache[name] = location;
        return location;
    }

    void ShaderProgram::SetUniform(const std::string& name, float value) {
        auto location = GetUniformLocation(name);
        glUniform1f(location, value);;
    }

    void ShaderProgram::SetUniform(const std::string& name, float v0, float v1) {
        auto location = GetUniformLocation(name);
        glUniform2f(location, v0, v1);
    }

}