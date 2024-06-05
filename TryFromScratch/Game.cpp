#include "Game.h"
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), imageTexture(nullptr), isRunning(false) {}

Game::~Game() {
    Clean();
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, 0);
        if (sdlRenderer) {
            renderer = new Renderer(sdlRenderer);
            SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        imageTexture = renderer->LoadTexture("tv.bmp");
        if (!imageTexture) {
            isRunning = false;
            return;
        }

        isRunning = true;
    }
    else {
        isRunning = false;
    }
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::Update() {
    // Game logic update
}

void Game::Render() {
    renderer->Clear();

    if (imageTexture) {
        SDL_Rect srcRect = { 0, 0, 800, 600 };  // Source rectangle
        SDL_Rect dstRect = { 0, 0, 800, 600 }; // Destination rectangle
        SDL_RenderCopy(renderer->GetSDLRenderer(), imageTexture, &srcRect, &dstRect);
    }

    renderer->Present();
}

void Game::Clean() {
    SDL_DestroyTexture(imageTexture);
    //delete renderer;
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
