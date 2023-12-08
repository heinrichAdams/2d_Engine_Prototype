#include <iostream>
#include "Renderer.h"
#include "Initialization.h"
#include "Draw.h"
#include "Clean.h"



int main(int argc, char* argv[])
{
	Renderer window = Renderer();


	InitializeSDL(window.window, window.renderer);
	while (true)
	{
		PrepareDraw(window.renderer);
		ExecuteDraw(window.renderer);
	}

	

	return 0;
}