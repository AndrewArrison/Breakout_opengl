#include "game.h"

// Game-related State data
SpriteRenderer  *Renderer;


Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{ 

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ShaderResourceManager::LoadShader("../src/shaders/sprite.vert", "../src/shaders/sprite.frag","sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ShaderResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ShaderResourceManager::GetShader("sprite").SetMatrix4f("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ShaderResourceManager::GetShader("sprite"));
    // load textures
    TextureResourceManager::LoadTexture("../src/Texture/Logo.png", true, "face");
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    Renderer->DrawSprite(TextureResourceManager::GetTexture("face"), glm::vec2(200.0f, 200.0f), glm::vec2(200.0f, 200.0f), 45.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}