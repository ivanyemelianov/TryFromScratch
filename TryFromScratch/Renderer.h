#pragma once

#include <SDL.h>
#include <string>

class Renderer {
public:
    Renderer(SDL_Renderer* ren);
    ~Renderer();

    void Clear();
    void Present();
    void DrawRect(int x, int y, int w, int h);
    SDL_Texture* LoadTexture(const std::string& filePath);
    SDL_Renderer* GetSDLRenderer() const;

private:
    SDL_Renderer* renderer;
};



