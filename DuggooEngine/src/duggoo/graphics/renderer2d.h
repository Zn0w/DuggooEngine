#pragma once

#include "../math/vector.h"

#include "renderable2d.h"

namespace dg { namespace graphics {

	class Renderer2D
	{
	public:
		virtual void submit(Renderable2D renderable) = 0;
		virtual void flush() = 0;
	};

} }