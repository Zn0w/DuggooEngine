#pragma once

namespace Duggoo
{	namespace graphics {

	struct Window
	{
		int x, y, width, height;
		const char* title;
	};

	Window createWindow(int x, int y, int width, int height, const char* title);

} }