#pragma once

namespace dg { namespace graphics {

	struct WindowData
	{
		int x, y, width, height;
		const char* title;

		// NOTE: In the future: struct Scene variable (struct Scene holds a collection of entities)
	};

} }