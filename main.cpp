#include "Engine.h"

int main(int argc, char* argv[]) {
	Engine* engine = new Engine();
	const int target = 60;
	const int frameTime = 1000 / target;
	Uint16 startTime = 0;
	int timeTaken = 0;
	if (engine->init("MatorX", 800, 600)) {
		while (engine->isRunning())
		{
			startTime = SDL_GetTicks();
			engine->handleEvents();
			engine->update();
			engine->render();
			timeTaken = SDL_GetTicks() - startTime;
			if (frameTime > timeTaken) {
				SDL_Delay(frameTime - timeTaken);
			}
		}
	}
	delete engine;
	return 0;
}