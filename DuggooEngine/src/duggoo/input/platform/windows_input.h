#pragma once

#include "../../graphics/platform/OpenglWindow.h"

namespace dg { namespace input {
	
	bool isKeyPressedImpl(int keycode)
	{
		int state = glfwGetKey(graphics::opengl::window.windowHandle, keycode);	//NOTE: using glfw ketcodes only for early testing purposes
		return state == GLFW_PRESS;
	}

} }