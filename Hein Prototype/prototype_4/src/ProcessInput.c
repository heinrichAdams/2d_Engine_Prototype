#include "ProcessInput.h"
#include "Window.h"
#include <SDL2/SDL.h>

extern Window window;

static void GetKeyDown(SDL_KeyboardEvent* keyEvent)
{
    // Check To Avoid Keyboard Repeat Events
    if(keyEvent->repeat == 0)
    {
        if (keyEvent->keysym.scancode == SDL_SCANCODE_W)
        {
            window.up = 1;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_S)
        {
            window.down = 1;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_A)
        {
            window.left = 1;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_D)
        {
            window.right = 1;
        }
        if(keyEvent->keysym.scancode == SDL_SCANCODE_SPACE)
        {
            window.shoot = 1;
        }
    }
}

static void GetKeyUp(SDL_KeyboardEvent* keyEvent)
{
    // Check To Avoid Keyboard Repeat Events
    if(keyEvent->repeat == 0)
    {
        if (keyEvent->keysym.scancode == SDL_SCANCODE_W)
        {
            window.up = 0;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_S)
        {
            window.down = 0;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_A)
        {
            window.left = 0;
        }
        if (keyEvent->keysym.scancode == SDL_SCANCODE_D)
        {
            window.right = 0;
        }
        if(keyEvent->keysym.scancode == SDL_SCANCODE_SPACE)
        {
            window.shoot = 0;
        }
    }
}

void GetInput(void)
{
    // Create Event Listener
    SDL_Event event;

    // While there are events that have not been processed
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_KEYDOWN:
                GetKeyDown(&event.key);
                break;

            case SDL_KEYUP:
                GetKeyUp(&event.key);
                break;

            default:
                break;
        }
    }

}