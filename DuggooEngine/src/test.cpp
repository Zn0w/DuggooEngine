#include "test.h"

#include <iostream>

namespace Duggoo
{

	bool game_running;
	
	void start()
	{
		std::cout << "Hello from Duggoo Engine!" << std::endl;

		game_running = true;
		int count = 0;

		std::cout << "Game init" << std::endl;

		while (game_running)
		{
			count++;
			game_running = count < 1000;

			std::cout << "Game refresh" << std::endl;
		}

		std::cout << "Game destroy" << std::endl;
		
		system("pause");
	}

}