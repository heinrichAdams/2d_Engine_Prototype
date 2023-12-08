#include "Engine.h"

Engine::Engine(const char* windowTitle, int windowWidth, int windowHeight,
	int windowFlags, int rendererFlags)
{
	window = new WindowHandler(windowTitle, windowWidth, windowHeight, 
		windowFlags, rendererFlags);


	continueRunning = false;
}

Engine::~Engine()
{

}

void Engine::Setup()
{
	continueRunning = true;
}

void Engine::ProcessLoop()
{
	while (continueRunning)
	{
		window->BackBuffer();
		window->FrontBuffer();
	}
}

void Engine::ProcessUserInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			
			break;
		default:
			break;
		}
	}
}

void Engine::Quit()
{
	window->Close();
	delete window;
	SDL_Quit();
}