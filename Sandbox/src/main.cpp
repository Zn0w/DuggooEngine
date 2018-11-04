#include <iostream>

#include <duggoo.h>

//namespace Duggoo
//{

	//__declspec(dllimport) void start();

//}

// ^^^^
// |||| This import is just for now

void main()
{
	//Duggoo::start();
	//system("pause");

	bool game_running;
	Duggoo::graphics::Window window;

	
	std::cout << "Hello from Duggoo Engine!" << std::endl;

	game_running = true;
	int count = 0;

	window = Duggoo::graphics::createWindow(0, 0, 640, 480, "Duggoo Engine Sandbox Window");

	std::cout << "Game init" << std::endl;

	/* Loop until the user closes the window or the game stops*/
	while (game_running && Duggoo::graphics::isOpen(window))
	{
		count++;
		game_running = count < 1000;

		Duggoo::graphics::prepareRender();
		Duggoo::graphics::render(window);

		Duggoo::graphics::updateWindow(window);

		std::cout << "Game refresh" << std::endl;
	}

	std::cout << "Game destroy" << std::endl;

	Duggoo::graphics::close();
}