#include "ProcessInput.h"
#include <SDL2/SDL.h>

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
            default:
                break;
        }
    }

}