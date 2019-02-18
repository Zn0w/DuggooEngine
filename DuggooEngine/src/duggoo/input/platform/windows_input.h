#pragma once

#include "../../graphics/platform/OpenglWindow.h"

namespace dg { namespace input {
	
	bool isKeyPressedImpl(int keycode)
	{
		int state = glfwGetKey(graphics::opengl::window.windowHandle, keycode);
		return state == GLFW_PRESS;
	}

} }