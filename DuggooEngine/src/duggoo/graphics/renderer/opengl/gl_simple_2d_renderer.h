#pragma once

#include <deque>	// Double-ended queue

#include <glad/glad.h>

#include "gl_renderer2d.h"

namespace dg {
	namespace graphics {

		class SimpleRenderer2D : public Renderer2D
		{
		private:
			std::deque<Renderable2D> renderQueue;

		public:
			void submit(Renderable2D renderable);	// Add the renderable to the render queue
			void flush();							// Render renderables in the queue
		};

	}
}