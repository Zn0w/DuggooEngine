#include "renderer.h"

#include <iostream>

namespace Duggoo
{	namespace graphics {

	void render(Window w)
	{
		std::cout << "Window is being rendered!" << std::endl;
		glfwSwapBuffers(w.glfw_window);
	}

	void prepareRender()
	{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);
	}

} }