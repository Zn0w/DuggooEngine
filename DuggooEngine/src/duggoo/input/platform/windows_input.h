#pragma once

#include "../../graphics/platform/OpenglWindow.h"

namespace dg { namespace input {
	
	bool isKeyPressedImpl(int keycode)
	{
		int state = glfwGetKey(graphics::opengl::window.windowHandle, GLFW_KEY_F);
		return state == GLFW_PRESS;
	}

} }