#include "Display.h"
#include "Window.h"
#include <SDL2/SDL.h>


extern Window window;

void UpdateBackBuffer(void)
{

    SDL_SetRenderDrawColor(window.renderer, 5, 5, 5, 255);
    SDL_RenderClear(window.renderer);

}

void UpdateFrontBuffer(void)
{

    SDL_RenderPresent(window.renderer);

}

SDL_Texture* LoadTextureFromFile(char* filePath)
{
    SDL_Texture* texture = NULL;

    // Send load data to log
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
    "loading image from path: %s", filePath);

    texture = IMG_LoadTexture(window.renderer, filePath);

    return texture;

}

void DrawTexture(SDL_Texture* texture, int xPos, int yPos)
{
    SDL_Rect surface;

    surface.x = xPos;
    surface.y = yPos;

    // Retrieve attributes of a texture
    SDL_QueryTexture(texture, NULL, NULL, &surface.w, &surface.h);

    SDL_RenderCopy(window.renderer, texture, NULL, &surface);

}