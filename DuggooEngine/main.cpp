// This file is made for testing purposes

#include <stdlib.h>
#include <stdio.h>

#include "src/duggoo.h"


class TestApplication : public dg::app::Application
{
public:
	GLFWwindow* window;
	bool debug = false;

	TestApplication()
		: dg::app::Application(dg::graphics::WindowProperties(1280, 720, false, false, "Test Application"), dg::app::OPENGL_2D)
	{}

	void onInit()
	{
		// init game logci stuff
	}

	void onUpdate(float delta_time)
	{
		if (debug)
			printf("Delta time: %fs  (%fms)\tFPS: %.0f\n", delta_time, delta_time * 1000.0f, 1.0 / delta_time);

		if (dg::input::isKeyPressed(DG_KEY_G))
		{
			if (debug)
				debug = false;
			else
				debug = true;
		}

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