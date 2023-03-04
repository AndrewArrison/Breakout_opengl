#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "../ResourceManager/texture_resource_manager.h"
#include "../ResourceManager/shader_resource_manager.h"
#include "../sprite_renderer.h"

//info Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
public:
    //info game state
    GameState               State;	
    bool                    Keys[1024];
    unsigned int            Width, Height;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif