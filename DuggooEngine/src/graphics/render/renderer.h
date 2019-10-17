#pragma once

#include "../../math/math.h"
#include "../buffers/vertex_array.h"
#include "shader.h"


namespace dg { namespace graphics {

	void Clear(math::Vector4 clear_color);
	void DrawIndexed(VertexArray* vertex_array);
	
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();
		static void SubmitMesh(VertexArray* va);
	};

} }