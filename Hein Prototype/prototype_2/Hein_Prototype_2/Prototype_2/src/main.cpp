#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	std::cout << "SDL Initialized Successfully" << std::endl;

	return 0;
}