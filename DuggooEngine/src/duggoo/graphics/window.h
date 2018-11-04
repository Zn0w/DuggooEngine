#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

namespace Duggoo
{	namespace graphics {

	struct Window
	{
		const char* title;
		int x, y, width, height;
		GLFWwindow* glfw_window;
	};

	Window createWindow(int x, int y, int width, int height, const char* title);

	bool isOpen(Window);

	void updateWindow(Window);

	void close();

} }