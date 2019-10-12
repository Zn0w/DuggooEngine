#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>


namespace dg { namespace gui {

	class Gui
	{
	public:
		virtual void init(GLFWwindow* window);
		virtual void destroy();
		virtual void render() = 0;
	};

} }