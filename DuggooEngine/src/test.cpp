#include "test.h"

#include "graphics/window.h"
#include "graphics/renderer.h"

#include <iostream>

#include <GLFW/glfw3.h>

namespace Duggoo
{

	bool game_running;
	graphics::Window window;
	
	void start()
	{
		std::cout << "Hello from Duggoo Engine!" << std::endl;

		game_running = true;
		int count = 0;

		window = graphics::createWindow(0, 0, 640, 480, "Duggoo Engine Sandbox Window");

		std::cout << "Game init" << std::endl;

		/* Loop until the user closes the window or the game stops*/
		while (game_running && graphics::isOpen(window))
		{
			count++;
			game_running = count < 1000;

			graphics::prepareRender();
			graphics::render(window);

			graphics::updateWindow(window);

			std::cout << "Game refresh" << std::endl;
		}

		std::cout << "Game destroy" << std::endl;

		graphics::close();
	}

}