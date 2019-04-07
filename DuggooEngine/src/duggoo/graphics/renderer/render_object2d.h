#pragma once

#include "../../math/math.h"
#include "../buffers/vertex_array.h"
#include "../buffers/index_buffer.h"

namespace dg { namespace graphics {

	class RenderObject2D
	{
	protected:
		math::Vector3 position;
		math::Vector2 size;
		math::Vector4 color;

		VertexArray* vertexArray;
		IndexBuffer* indexBuffer;

	public:
		RenderObject2D(math::Vector3 s_position, math::Vector2 s_size, math::Vector4 s_color)
			: position(s_position), size(s_size), color(s_color)
		{
			
		}

		virtual ~RenderObject2D()
		{
			delete vertexArray;
			delete indexBuffer;
		}

		VertexArray* getVAO() { return vertexArray; }
		IndexBuffer* getIBO() { return indexBuffer; }

		math::Vector3 getPosition() { return position; };
		math::Vector2 getSize() { return size; };
		math::Vector4 getColor() { return color; };
	};

} }