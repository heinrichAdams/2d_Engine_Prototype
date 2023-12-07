#include "Engine.h"

Engine::Engine(const char* windowTitle, int windowWidth, int windowHeight,
	int windowFlags, int rendererFlags)
{
	window = new WindowHandler(windowTitle, windowWidth, windowHeight, 
		windowFlags, rendererFlags);

	userInput = new InputHandler();

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
		continueRunning = userInput->HandleEventQue();
	}
}

void Engine::Quit()
{
	delete window;
	delete userInput;
	SDL_Quit();
}