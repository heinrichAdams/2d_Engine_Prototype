#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "Config.h" 
#include "Window.h" 
#include "Entity.h"
#include "GameLogic.h"
#include "Display.h"
#include "ProcessInput.h"
#include "Game.h"


// GLOBAL VARIABLES
// ---------------------------------------------
Window window;
Game game;
// ---------------------------------------------

// FUNCTION PROTOTYPES
// ---------------------------------------------
void Initialize(void);
void Clean(void);
void LimitFramerate(long* previousFrame, float* remainder);
// ---------------------------------------------


int main(int argc, char* argv[])
{
    memset(&window, 0,sizeof(Window));

    Initialize();

    atexit(Clean);

    InitializeGame();

    long previousFrame = SDL_GetTicks();
    float remainder = 0;

    while(true)
    {
        UpdateBackBuffer();

        GetInput();

        window.send.Update();

        window.send.RenderGameObjects();

        UpdateFrontBuffer();

        LimitFramerate(&previousFrame, &remainder);
        
    }


    return 0;
}

void LimitFramerate(long* previousFrame, float* remainder)
{
    long wait = 16 + *remainder;
    long frameTime = SDL_GetTicks() - *previousFrame;

    *remainder -= (int)*remainder;

    wait -= frameTime;

    if(wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *previousFrame = SDL_GetTicks();
}

void Initialize(void)
{
    int windowFlags = 0;
    int renderFlags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;

    // INITIALIZE SDL VIDEO

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("[COULDNT INITIALIZE SDL VIDEO]");
		exit(1);
    }

    // INITIALIZE WINDOW

    window.window = SDL_CreateWindow(WINDOW_TITLE, 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    windowFlags);

    if(!window.window)
    {
        printf("COULDNT CREATE SDL WINDOW\n");
		exit(1);
    }

    // USE SDL HINT TO SET SCALING METHOD
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // INITIALIZE RENDERER
    window.renderer = SDL_CreateRenderer(window.window, -1, renderFlags);
    
    if(!window.renderer)
    {
        printf("COULDNT CREATE SDL RENDERER\n");
		exit(1);
    }

    // INITIALIZE SDL_IMAGE
    IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);

}

void Clean(void)
{
    IMG_Quit();
    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
}