#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>


namespace dg { namespace gui {

	class Gui
	{
		bool show_demo_window;
		bool show_another_window;
		ImVec4 clear_color;

	public:
		void init(GLFWwindow* window);
		void destroy();
		void render();
	};

} }