#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:

	int windowWidth;
	int windowHeight;

	Game();
	~Game();

	void Initialize();

	void Setup();
	void Run();
	void EventListener();
	void Update();
	void Draw();

	void Exit();

};

#endif