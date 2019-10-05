#pragma once

//#include "../../event/key_event.h"
//#include "../../event/mouse_event.h"

//#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


namespace dg { namespace graphics {

	struct Window
	{
		int x, y, width, height;
		const char* title;
		GLFWwindow* windowHandle;
	};

	static Window window;

	bool initWindow(int width, int height, const char* title)
	{
		window.width = width;
		window.height = height;
		window.title = title;

		if (!glfwInit())
			return false;

		window.windowHandle = glfwCreateWindow(
												window.width,
												window.height,
												window.title,
												NULL, NULL
											  );
		if (!window.windowHandle)
		{
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window.windowHandle);

		//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);		// NOTE: In order to be able to use opengl functions

		return true;
	}

	bool windowClosed()
	{
		return glfwWindowShouldClose(window.windowHandle);
	}

	void windowRefresh()
	{
		glfwSwapBuffers(window.windowHandle);

		glfwPollEvents();
	}

	void windowDestroy()
	{
		glfwDestroyWindow(window.windowHandle);
		glfwTerminate();
	}

} }