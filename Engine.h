#define SDL_MAIN_HANDLED
#pragma once
#include <SDL2/SDL.h>

class Engine
{
public:
	Engine();
	~Engine();
	bool init(char* title, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();
	void isRunning() {}
private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

Engine::Engine()
{}

Engine::~Engine()
{}