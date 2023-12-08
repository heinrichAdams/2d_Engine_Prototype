#include "Draw.h"

void PrepareDraw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
}

void ExecuteDraw(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
}
