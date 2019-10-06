#pragma once

#include "GLFW/glfw3.h"


namespace dg { namespace input {
	
	class Input
	{
	private:
		GLFWwindow* window;

	public:
		void setWindow(GLFWwindow* handle) { window = handle; }
		
		bool isKeyPressed(int keycode);
		bool isKeyReleased(int keycode);

		// NOTE: possibly the return value of this function will be a vertex of x and y in the future
		void getMousePosition(int* x, int* y);

		bool isMouseButtonPressed(int mouseButtonCode);

		// NOTE: mouse scrolled event will be added in the future
	};

} }