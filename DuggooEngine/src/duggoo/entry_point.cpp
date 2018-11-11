// It will be in main function of the game

#include "entry_point.h"

#include "../duggoo.h"

#include <iostream>

__declspec(dllexport) void start()
{
	Duggoo::app::Application game;


	std::cout << "Hello from Duggoo Engine Sandbox!" << std::endl;

	game.game_running = true;
	int count = 0;

	game.window = Duggoo::graphics::createWindow(0, 0, 640, 480, "Duggoo Engine Sandbox Window");

	std::cout << "Game init" << std::endl;

	/* Loop until the user closes the window or the game stops*/
	while (game.game_running && Duggoo::graphics::isOpen(game.window))
	{
		std::cout << "Game update" << std::endl;
		
		count++;
		game.game_running = count < 1000; // Game will automatically close when its loop does 1000 iterations (test loop)

		game.update();
		game.draw();
	}

	std::cout << "Game destroy" << std::endl;

	Duggoo::graphics::close();
}