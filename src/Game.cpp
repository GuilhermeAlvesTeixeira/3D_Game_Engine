#include "Game.h"

#include <GLFW/glfw3.h>
#include <iostream>

bool Game::Init() {
    return true;
}
void Game::Update(float deltaTime) {
    //std::cout << "Current delta: " << deltaTime << std::endl;
    auto& input = eng::Engine::GetInstance().GetInputManager();

    if(input.IsKeyPressed(GLFW_KEY_A)) {
        std::cout << "[A] button is pressed" << "\n";
    }
}
void Game::Destroy() {

}