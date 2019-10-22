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
		glDrawElements(GL_TRIANGLES, vertex_array->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
	}


	// Renderer class functions

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
	
	}
	
	void Renderer::EndScene()
	{
	
	}
	
	void Renderer::SubmitMesh(VertexArray* va)
	{
		// TODO: Submit into render command queue

		va->bind();
		DrawIndexed(va);  // for test
	}

} }