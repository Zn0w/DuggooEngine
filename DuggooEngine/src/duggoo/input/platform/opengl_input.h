#pragma once

#include "../../graphics/platform/OpenglWindow.h"

namespace dg { namespace input {
	
	bool isKeyPressedImpl(int keycode)
	{
		int state = glfwGetKey(graphics::opengl::window.windowHandle, keycode);
		return state == GLFW_PRESS;
	}

	// NOTE: possibly the return value of this function will be a vertex of x and y in the future
	void getMousePositionImpl(int* x, int* y)
	{
		// NOTE: workaround for converting double pointers to int pointers (temporary solution)
		double xpos, ypos;
		glfwGetCursorPos(graphics::opengl::window.windowHandle, &xpos, &ypos);
		
		int sx, sy;
		sx = xpos;
		sy = ypos;

		*x = sx;
		*y = sy;
	}

	bool isMouseButtonPressedImpl(int mouseButtonCode)
	{
		int state = glfwGetMouseButton(graphics::opengl::window.windowHandle, mouseButtonCode);
		return state == GLFW_PRESS;
	}

	// NOTE: mouse scrolled event will be added in the future

} }