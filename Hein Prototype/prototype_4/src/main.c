#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "Config.h" 
#include "Window.h" 

// GLOBAL VARIABLES
// ---------------------------------------------
Window window;
// ---------------------------------------------

// FUNCTION PROTOTYPES
// ---------------------------------------------
void Initialize(void);
void Clean(void);
// ---------------------------------------------


int main(int argc, char* argv[])
{
    memset(&window,0 ,sizeof(Window));

    Initialize();

    atexit(Clean);


    return 0;
}

void Initialize(void)
{
    int windowFlags = 0;
    int renderFlags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;

    // INITIALIZE SDL VIDEO

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        print
    }


}

void Clean(void)
{
    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
}