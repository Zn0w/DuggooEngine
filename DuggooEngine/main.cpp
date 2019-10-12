// This file is made for testing purposes

#include <stdlib.h>
#include <stdio.h>

#include "src/app/application.h"
#include "src/input/keycodes.h"
#include "src/input/mouse_button_codes.h"


class TestApplication : public dg::app::Application
{
	bool debug = false;
public:
	TestApplication()
		: Application(dg::graphics::WindowProperties(1280, 720, true, false, "Test Application"), dg::app::OPENGL_2D)
	{}

	void onInit()
	{
		// init game logic stuff
	}

	void onUpdate(float delta_time)
	{
		// game logic update
	}

	void onDestroy()
	{
		// save game state, etc
	}
};

TestApplication myApp;

int main()
{
	// start up engine systems in the correct order (it will be put in a seperate engine file e.g. SystemsManager.h)

	myApp.start();

	//shut down the systems in reverse order (it will be put in a seperate engine file e.g. SystemsManager.h)

	return 0;
}