#include "InputHandler.h"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{
	
}

bool InputHandler::HandleEventQue()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return false;
			break;
		default:
			break;
		}
	}

	return true;
}