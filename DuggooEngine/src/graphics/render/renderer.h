#pragma once

#include <glad/glad.h>

#include "../buffers/vertex_array.h"
#include "../buffers/indexbuffer.h"
#include "shader.h"

namespace dg { namespace graphics {

	class Renderer
	{
	public:
		void render(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	};

} }