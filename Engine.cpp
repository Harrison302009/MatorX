#include <iostream>
#include "Engine.h"
using namespace std;

Engine::Engine() : m_running(false), m_window(nullptr), m_renderer(nullptr) {}
Engine::~Engine() {
	clean();
}

bool Engine::init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize. Error: " << SDL_GetError() << endl;
		return false;
	}
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer || !m_window) {
		cout << "Encountered an error while creating window or renderer. Error: " << SDL_GetError() << endl;
		return false;
	}
	m_running = true;
	cout << "SDL initialized successfully." << endl;
	return true;
}

void Engine::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			m_running = false;
		}
	}
}

void Engine::update() {
	//cout << "Updating game state..." << endl;
}

void Engine::render() {
	SDL_SetRenderDrawColor(m_renderer, 18, 111, 206, 237);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Engine::clean() {
	if (m_renderer) {
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
	if (m_window) {
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
}