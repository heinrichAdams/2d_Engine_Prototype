#ifndef WINDOW_H 
#define WINDOW_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

typedef struct
{
    SDL_Renderer* renderer;
    SDL_Window* window;
} Window ;


#endif