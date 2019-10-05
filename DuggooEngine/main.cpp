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

		float ratio;
		int width = dg::graphics::window.width, height = dg::graphics::window.height;
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
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