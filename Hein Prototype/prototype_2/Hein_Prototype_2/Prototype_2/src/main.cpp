#include <SDL.h>
#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine engine("Test Window", 
		1280, 
		720, 
		0 , 
		SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	
	engine.Setup();

	engine.ProcessLoop();

	engine.Quit();

	return 0;
}