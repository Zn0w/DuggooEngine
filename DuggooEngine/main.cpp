// This file is made for testing purposes

#include <stdlib.h>
#include <stdio.h>

#include "src/duggoo.h"
#include "src/graphics/window/window.h"


class TestApplication : public dg::app::Application
{
public:
	GLFWwindow* window;
	bool debug = false;

	void onInit()
	{
		if (!dg::graphics::initWindow(640, 480, "Test Application"))
			printf("GLFW failed\n");
	}

	void onUpdate(float delta_time)
	{
		if (debug)
			printf("Delta time: %fs  (%fms)\tFPS: %.0f\n", delta_time, delta_time * 1000.0f, 1.0 / delta_time);

		if (dg::graphics::windowClosed())
		{
			running = false;
			return;
		}

		int width = dg::graphics::window.width;
		int height = dg::graphics::window.height;
		glViewport(0, 0, width, height);
		glClearColor(0.0f, 0.3f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		dg::graphics::windowRefresh();

		if (dg::input::isKeyPressed(DG_KEY_G))
		{
			if (debug)
				debug = false;
			else
				debug = true;
		}
	}

	void onDestroy()
	{
		dg::graphics::windowDestroy();
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