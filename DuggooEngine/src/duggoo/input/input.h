#pragma once

#ifdef DG_PLATFORM_WINDOWS
	#include "platform/windows_input.h"
#endif

namespace dg { namespace input {
	
	bool(*isKeyPressed) (int keycode) = isKeyPressedImpl;

} }