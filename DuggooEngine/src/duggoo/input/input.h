#pragma once

#ifdef DG_PLATFORM_WINDOWS
	#include "platform/opengl_input.h"
#endif

namespace dg { namespace input {
	
	bool(*isKeyPressed) (int keycode) = isKeyPressedImpl;

	void(*getMousePosition) (int* x, int* y) = getMousePositionImpl;

	bool(*isMouseButtonPressed) (int mouseButtonCode) = isMouseButtonPressedImpl;

} }