#include "entry_point.h"

#include "../duggoo.h"

class Game : public Duggoo::app::Application
{
private:
	int counter = 0;

public:
	Game(const char* t)
		: Duggoo::app::Application(t)
	{
		
	}
	
	void update()
	{
		counter++;
		
		if (counter >= 999999999)
			running = false;
	}
};

__declspec(dllexport) void start()
{
	WinMain(0, 0, 0, 0);
	Duggoo::log(Duggoo::INFO, "Hello World! :)");

	Game my_game("Sandbox");

	while (my_game.isRunning())
	{
		my_game.update();
	}
}