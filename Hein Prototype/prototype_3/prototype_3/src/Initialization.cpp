#include "Initialization.h"
#include <iostream>

void InitializeSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	// INITIALIZE SDL VIDEO
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "\x1B[91m"
			<< "ERROR ["
			<< "COULD NOT INITIALIZE SDL VIDEO"
			<< "]"
			<< "\033[0m"
			<< std::endl;
		exit(1);
	}

	std::cout << "\x1B[32m"
		<< "LOG ["
		<< "SDL_VIDEO SUCCESSFULLY INITIALIZED"
		<< "]"
		<< "\033[0m"
		<< std::endl;

	// CREATE SDL WINDOW
	window = SDL_CreateWindow(TITLE,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		WINDOW_FLAGS);

	if (!window)
	{
		std::cout << "\x1B[91m"
			<< "ERROR ["
			<< "COULD NOT CREATE SDL WINDOW"
			<< "]"
			<< "\033[0m"
			<< std::endl;
		exit(1);
	}

	std::cout << "\x1B[32m"
		<< "LOG ["
		<< "WINDOW SUCCESSFULLY CONSTRUCTED"
		<< "]"
		<< "\033[0m"
		<< std::endl;

	// Hint is a rule that tries to run but if it fails it just 
	// does nothing without affect program flow

	// Set the scaling technique
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	// CREATE RENDERER
	renderer = SDL_CreateRenderer(window, -1, RENDERER_FLAGS);

	if (!renderer)
	{
		std::cout << "\x1B[91m"
			<< "ERROR ["
			<< "COULD NOT CREATE SDL RENDERER"
			<< "]"
			<< "\033[0m"
			<< std::endl;
		exit(1);
	}

	std::cout << "\x1B[32m"
		<< "LOG ["
		<< "RENDERER SUCCESSFULLY CONSTRUCTED"
		<< "]"
		<< "\033[0m"
		<< std::endl;


}