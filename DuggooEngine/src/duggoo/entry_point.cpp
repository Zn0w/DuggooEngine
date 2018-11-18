#include "entry_point.h"

#include "../duggoo.h"

__declspec(dllexport) void start()
{
	Duggoo::app::Application game;


	Duggoo::log(Duggoo::INFO, "Hello from Duggoo Engine Sandbox!");

	Duggoo::log(Duggoo::TRACE, "Game init");
	
	game.game_running = true;
	int count = 0;

	game.window = Duggoo::graphics::createWindow(0, 0, 640, 480, "Duggoo Engine Sandbox Window");

	/* Loop until the user closes the window or the game stops*/
	while (game.game_running && Duggoo::graphics::isOpen(game.window))
	{
		Duggoo::log(Duggoo::TRACE, "Game update");
		
		count++;
		game.game_running = count < 1000; // Game will automatically close when its loop does 1000 iterations (test loop)

		game.update();
		game.draw();
	}

	Duggoo::log(Duggoo::TRACE, "Game destroy");

	Duggoo::log(Duggoo::INFO, "Testing premake5.");

	Duggoo::graphics::close();
}