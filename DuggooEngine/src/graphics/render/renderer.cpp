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

	SceneData* Renderer::scene_data = new SceneData;

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		scene_data->viewprojection_matrix = camera.getViewProjectionMatrix();
	}
	
	void Renderer::EndScene()
	{
	
	}
	
	void Renderer::SubmitMesh(Shader* shader, VertexArray* va)
	{
		// TODO: Submit into render command queue

		shader->bind();
		shader->uploadUniformMat4f("u_ViewProjection", scene_data->viewprojection_matrix);

		va->bind();
		DrawIndexed(va);  // for test
	}

} }