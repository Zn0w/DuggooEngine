#pragma once

#include "../buffers/platform/gl_buffer.h"
#include "../buffers/platform/gl_indexbuffer.h"
#include "../buffers/platform/gl_vertex_array.h"
#include "../../math/vector.h"

namespace dg { namespace graphics {

	class Renderable2D
	{
	protected:
		math::Vector3 position;
		math::Vector2 size;
		math::Vector4 color;

		VertexArray* vertexArray;
		IndexBuffer* indexBuffer;

	public:
		Renderable2D(math::Vector3 s_position, math::Vector2 s_size, math::Vector4 s_color)
			: position(s_position), size(s_size), color(s_color)
		{
			vertexArray = new VertexArray();
			GLfloat vertices[] =						// 4 points, representing rectangle
			{
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
			};

			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
			
			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };		// A triangle
			indexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
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