#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "vector"

#include "../ResourceManager/texture_resource_manager.h"
#include "../ResourceManager/shader_resource_manager.h"
#include "../SpriteRenderer/sprite_renderer.h"
#include "../Entity/entity.h"
#include "../Entity/Ball/ball.h"
#include "../Level/level.h"

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
    std::vector<GameLevel> Levels;
    unsigned int           Level;
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