#include "Game.h"
#include <iostream>


Game::Game()
{
    isRunning = false;
    window = nullptr;
    renderer = nullptr;

}

Game::~Game()
{

}

void Game::Initialize()
{
    // INIT SDL 

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "ERROR INITIALIZING SDL..." << std::endl;
        return;
    }
    
    // Create Window

    window = SDL_CreateWindow(
        "Prototype", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        NULL);

    if (!window)
    {
        std::cerr << "ERROR CREATING SDL WINDOW..." << std::endl;
        return;
    }

    // Create Renderer

    renderer = SDL_CreateRenderer(window, -1, NULL);

    if (!renderer)
    {
        std::cerr << "ERROR CREATING SDL RENDERER..." << std::endl;
        return;
    }

    isRunning = true;

}

void Game::Run()
{
    while (isRunning)
    {
      EventListener();
      Update();
      Draw();
	}
}

void Game::EventListener()
{
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            break;
        default:
            break;
        }
            
    }
}

void Game::Update()
{
    // Update Game
}

void Game::Draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render Updated Game

    SDL_RenderPresent(renderer);
}

void Game::Exit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
