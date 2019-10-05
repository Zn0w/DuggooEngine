#pragma once

#include "../graphics/window/window.h"

namespace dg { namespace input {
	
	bool isKeyPressed(int keycode)
	{
		int state = glfwGetKey(graphics::window.windowHandle, keycode);
		return state == GLFW_PRESS;
	}

	// NOTE: possibly the return value of this function will be a vertex of x and y in the future
	void getMousePosition(int* x, int* y)
	{
		// NOTE: workaround for converting double pointers to int pointers (temporary solution)
		double xpos, ypos;
		glfwGetCursorPos(graphics::window.windowHandle, &xpos, &ypos);
		
		int sx, sy;
		sx = xpos;
		sy = ypos;

		*x = sx;
		*y = sy;
	}

	bool isMouseButtonPressed(int mouseButtonCode)
	{
		int state = glfwGetMouseButton(graphics::window.windowHandle, mouseButtonCode);
		return state == GLFW_PRESS;
	}

	// NOTE: mouse scrolled event will be added in the future

} }