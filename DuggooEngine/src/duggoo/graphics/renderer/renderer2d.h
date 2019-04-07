#pragma once

#include "../../math/vector.h"

#include "render_object2d.h"

namespace dg { namespace graphics {

	class Renderer2D
	{
	public:
		virtual void submit(RenderObject2D renderObject) = 0;
		virtual void flush() = 0;
	};

} }