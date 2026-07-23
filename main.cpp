#include "Engine.h"

int main(int argc, char* argv[]) {
	Engine* engine = new Engine();
	if (engine->init("MatorX", 800, 600)) {
		while (engine->isRunning())
		{
			engine->handleEvents();
			engine->update();
			engine->render();
		}
	}
	delete engine;
	return 0;
}