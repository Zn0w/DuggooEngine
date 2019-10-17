#pragma once

#include "renderer.h"

#include <glad/glad.h>


namespace dg { namespace graphics {
	
	void Clear(math::Vector4 clear_color)
	{
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void DrawIndexed(VertexArray* vertex_array)
	{
		
	}

	void Renderer::BeginScene()
	{
	
	}
	
	void Renderer::EndScene()
	{
	
	}
	
	void Renderer::SubmitMesh(VertexArray* va)
	{
	
	}

} }