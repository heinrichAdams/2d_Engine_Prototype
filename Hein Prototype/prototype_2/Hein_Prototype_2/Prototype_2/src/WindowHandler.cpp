#include "WindowHandler.h"

WindowHandler::WindowHandler(const char* windowTitle, int windowWidth, int windowHeight,
	int windowFlags, int rendererFlags)
{
	renderer = nullptr;
	window = nullptr;

	WindowTitle = windowTitle;
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	WindowFlags = windowFlags;
	RendererFlags = rendererFlags;

	InitializeSDLVideo();
}

WindowHandler::~WindowHandler()
{
	
}

void WindowHandler::Close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void WindowHandler::InitializeSDLVideo()
{
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

	window = SDL_CreateWindow(
		WindowTitle, 
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WindowWidth,
		WindowHeight,
		WindowFlags);

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


	// -1 for default graphics exelleration device. 
	// If youve got a GPU as your default it will use that, 
	// If not, it will try to just use your cpu (software rendering)
	renderer = SDL_CreateRenderer(window, -1, RendererFlags);

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

void WindowHandler::BackBuffer()
{
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
}

void WindowHandler::FrontBuffer()
{
	SDL_RenderPresent(renderer);
}