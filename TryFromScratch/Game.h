#pragma once

#include <SDL.h>
#include "renderer.h"

class Game {
public:
    Game();
    ~Game();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    Renderer* renderer;
    SDL_Texture* imageTexture;
};



