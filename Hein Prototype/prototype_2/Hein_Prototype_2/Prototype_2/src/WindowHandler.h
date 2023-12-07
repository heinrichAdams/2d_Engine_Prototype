#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

#include <iostream>
#include <SDL.h>

class WindowHandler
{
private:

	SDL_Renderer* renderer;
	SDL_Window* window;

	void InitializeSDLVideo();

	const char* WindowTitle;

	int WindowWidth;
	int WindowHeight;

	int WindowFlags;
	int RendererFlags;

public:

	WindowHandler(const char* windowTitle, int windowWidth, int windowHeight, 
		int windowFlags, int rendererFlags);

	~WindowHandler();

	void BackBuffer();
	void FrontBuffer();
	void Close();
};


#endif