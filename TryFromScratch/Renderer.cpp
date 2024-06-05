#include "Renderer.h"
#include <SDL_image.h>
#include <iostream>

Renderer::Renderer(SDL_Renderer* ren) : renderer(ren) {}

Renderer::~Renderer() {}

void Renderer::Clear() {
    SDL_RenderClear(renderer);
}

void Renderer::Present() {
    SDL_RenderPresent(renderer);
}

void Renderer::DrawRect(int x, int y, int w, int h) {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

SDL_Texture* Renderer::LoadTexture(const std::string& filePath) {
    SDL_Surface* tempSurface = SDL_LoadBMP(filePath.c_str());
    if (tempSurface == nullptr) {
        std::cerr << "Unable to load BMP file: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (texture == nullptr) {
        std::cerr << "Unable to create texture from surface: " << SDL_GetError() << std::endl;
    }

    return texture;
}

SDL_Renderer* Renderer::GetSDLRenderer() const {
    return renderer;
}

