#include "entry_point.h"

#include "../duggoo.h"

#include "graphics/graphics_entry.h"

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
		//counter++;
		
		//if (counter >= 999999999)
			//running = false;
	}
};

__declspec(dllexport) void start()
{
	Duggoo::log(Duggoo::INFO, "Hello World! :)");

	Game my_game("Sandbox");
	
	my_game.setWindow(200, 200, 500, 500, "This is a test!");

	Duggoo::graphics::initGraphics(&(my_game.window));

	while (my_game.isRunning() && my_game.window.opened)
	{
		my_game.update();
	}
}