#ifndef WINDOW_H 
#define WINDOW_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "Send.h"
#include "Config.h"

typedef struct
{
    SDL_Renderer* renderer;
    SDL_Window* window;

    // Inputs
    int keys[KEYBOARD_SIZE];

    // Function Pointers to Delegate Rendering and Input to GameLogic Module
    Send send;
    
} Window;


#endif