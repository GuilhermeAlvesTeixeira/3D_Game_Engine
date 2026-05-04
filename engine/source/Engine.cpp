#include "Engine.h"
#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace eng 
{
    bool Engine::Init(int width, int height) {
        if (!m_application) {
            return false;
        }

        if(!glfwInit()) {
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, "Game Engine 3D", nullptr, nullptr);

        if(!m_window) {
            std::cout << "Error creating window\n";
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Falha ao inicializar GLAD\n";
            glfwTerminate();
            return false;
        }
    
        return m_application->Init();
    }

    void Engine::Run() {
        if(!m_application) { return; }

        m_lastTimePoint = std::chrono::steady_clock::now();
        while(!glfwWindowShouldClose(m_window) && !m_application -> NeedsToBeClosed()) {
            
            //processa eventos
            glfwPollEvents();

            //Atualiza
            auto now = std::chrono::steady_clock::now();
            float deltaTime = std::chrono::duration<float>(now - m_lastTimePoint).count();
            m_lastTimePoint = now;

            m_application->Update(deltaTime);
            
            //Renderiza
            glfwSwapBuffers(m_window);
        }
    }

    void Engine::Destroy(){
        if(m_application) {
            m_application->Destroy();
            m_application.reset();
            glfwTerminate();
            m_window = nullptr;
        }
    }

    void Engine::SetApplication(Application* app) {
        m_application.reset(app);
    }

    Application* Engine::GetApplication() {
        return m_application.get();
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}