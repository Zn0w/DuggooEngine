#pragma once

#include <vector>

#include "../math/vector.h"

namespace dg { namespace graphics {

	enum Shape
	{
		// This will be edited
		
		Pixel,
		Line,
		
		Rectangle,
		Triangle,
		Ellipse,

		Cube,
		Pyramid,
		Parallelepiped
	};
	
	class Renderer
	{
	
		virtual void flush() = 0;

		virtual void render(math::Vector2) = 0;

	};

} }