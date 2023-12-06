#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>


class Game
{
private:
	const int FPS = 60;
	const int MILLISECONDS_PER_FRAME = 1000 / FPS;

	bool isRunning;
	int millisecondsSincePreviousFrame;
	double deltaTime;
	int timeToWait;
	SDL_Window* window;
	SDL_Renderer* renderer;
	glm::vec2 playerPosition;
	glm::vec2 playerVelocity;

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