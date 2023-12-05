#include "Game.h"
#include <iostream>


Game::Game()
{
    isRunning = false;
    window = nullptr;
    renderer = nullptr;
    windowWidth = 0;
    windowHeight = 0;
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

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);

    windowWidth = 1280;
    windowHeight = 720;

    window = SDL_CreateWindow(
        "Prototype", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        NULL);

    if (!window)
    {
        std::cerr << "ERROR CREATING SDL WINDOW..." << std::endl;
        return;
    }

    // Create Renderer

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        std::cerr << "ERROR CREATING SDL RENDERER..." << std::endl;
        return;
    }

    // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    isRunning = true;

}

void Game::Setup()
{

}

void Game::Run()
{
    Setup();
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
    SDL_SetRenderDrawColor(renderer, 25, 20, 40, 255);
    SDL_RenderClear(renderer);

    // Update Back-Buffer
    
    // Texture Loading
    SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect destinationRect = {70,70,32,32};

    SDL_RenderCopy(renderer, texture, NULL, &destinationRect);

    SDL_DestroyTexture(texture);
    // Texture Loading


    // Render Back-Buffer as Front-Buffer
    SDL_RenderPresent(renderer);
}

void Game::Exit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
