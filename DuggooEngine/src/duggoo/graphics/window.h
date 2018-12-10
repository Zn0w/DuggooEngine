#pragma once

namespace Duggoo { namespace graphics {

		struct Window
		{
			int x, y, width, height;
			const char* title;
			bool opened;
			// Dynamic array of entities, etc ...
		};

} }