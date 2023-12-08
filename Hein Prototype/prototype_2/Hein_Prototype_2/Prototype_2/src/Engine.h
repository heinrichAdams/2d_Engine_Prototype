#ifndef ENGINE_H
#define ENGINE_H

#include "WindowHandler.h"
#include "InputHandler.h"
#include <SDL.h>

class Engine
{
private:
	
	bool continueRunning;
	WindowHandler* window;

public:

	Engine(const char* windowTitle, int windowWidth, int windowHeight,
		int windowFlags, int rendererFlags);
	~Engine();

	void Setup();
	void ProcessLoop();
	void ProcessUserInput();
	void Quit();

};

#endif