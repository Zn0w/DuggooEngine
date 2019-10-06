#pragma once

//#include "../../event/key_event.h"
//#include "../../event/mouse_event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


namespace dg { namespace graphics {

	struct WindowProperties
	{
		int width, height;
		bool vsync, fullscreen;
		const char* title;

		WindowProperties(int w_width, int w_height, bool w_vsync, bool w_fullscreen, const char* w_title)
			: width(w_width), height(w_height), vsync(w_vsync), fullscreen(w_fullscreen), title(w_title)
		{}
	};
	
	struct Window
	{
		WindowProperties properties;
		GLFWwindow* windowHandle;
	};

	static Window window;

	bool initWindow()
	{
		if (!glfwInit())
			return false;

		window.windowHandle = glfwCreateWindow(
												window.properties.width,
												window.properties.height,
												window.properties.title,
												NULL, NULL
											  );
		if (!window.windowHandle)
		{
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window.windowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to init GLAD" << std::endl;
			return false;
		}

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