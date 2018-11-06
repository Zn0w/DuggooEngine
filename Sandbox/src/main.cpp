#include <iostream>

#include <duggoo.h>

//namespace Duggoo
//{

	//__declspec(dllimport) void start();

//}

// ^^^^
// |||| This import is just for now

int main()
{
	//Duggoo::start();
	//system("pause");

	Duggoo::app::Application game;

	
	std::cout << "Hello from Duggoo Engine Sandbox!" << std::endl;

	game.game_running = true;
	int count = 0;

	game.window = Duggoo::graphics::createWindow(0, 0, 640, 480, "Duggoo Engine Sandbox Window");

	std::cout << "Game init" << std::endl;

	/* Loop until the user closes the window or the game stops*/
	while (game.game_running && Duggoo::graphics::isOpen(game.window))
	{
		count++;
		game.game_running = count < 1000;

		game.draw();

		std::cout << "Game refresh" << std::endl;
	}

	std::cout << "Game destroy" << std::endl;

	Duggoo::graphics::close();
}