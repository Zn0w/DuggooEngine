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

		WindowProperties() {}
		
		WindowProperties(int w_width, int w_height, bool w_vsync, bool w_fullscreen, const char* w_title)
			: width(w_width), height(w_height), vsync(w_vsync), fullscreen(w_fullscreen), title(w_title)
		{}
	};
	
	class Window
	{
	public:
		WindowProperties properties;
		GLFWwindow* windowHandle;

	public:
		bool init();
		bool isClosed();
		void refresh();
		void destroy();
	};

} }