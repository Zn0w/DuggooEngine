#pragma once

#include "../../math/math.h"
#include "../buffers/vertex_array.h"
#include "shader.h"
#include "camera.h"


namespace dg { namespace graphics {

	void Clear(math::Vector4 clear_color);
	void DrawIndexed(VertexArray* vertex_array);

	struct SceneData
	{
		glm::mat4 viewprojection_matrix;
	};
	
	class Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		static void SubmitMesh(Shader* shader, VertexArray* va);
	private:
		static SceneData* scene_data;
	};

} }