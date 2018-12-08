#define _CRT_SECURE_NO_WARNINGS // To use strcat() from string.h with VS compiler

#include "application.h"

namespace Duggoo { namespace app {

	Application::Application(const char* t)
	{
		title = t;
		running = true;

		char init_message[150];
		strcpy(init_message, "Application created: ");
		strcat(init_message, title);

		Duggoo::log(Duggoo::INFO, init_message);
	}

	Application::~Application()
	{
		char destroy_message[150];
		strcpy(destroy_message, "Application destroyed: ");
		strcat(destroy_message, title);
		
		Duggoo::log(Duggoo::INFO, destroy_message);
	}

	bool Application::isRunning()
	{
		return running;
	}

	void Application::setWindow(int x_pos, int y_pos, int w, int h, const char* t)
	{
		window.x = x_pos;
		window.y = y_pos;
		window.width = w;
		window.height = h;
		window.title = t;
	}

} }