#pragma once

#include <glm.hpp>


namespace dg { namespace graphics {

	class OrthographicCamera
	{
	private:
		glm::mat4 projection_matrix;
		glm::mat4 view_matrix;
		glm::mat4 viewprojection_matrix;			// caching the result projection_matrix * view_matrix	NOTE: maybe not cache in the future
		glm::vec3 position = {0.0f, 0.0f, 0.0f};	// Z axis rotation	NOTE: you don't have to init position, it will be set automatically in newer glm versions
		float rotation = 0.0f;

	public:
		OrthographicCamera(float left, float right, float bottom, float top, float near = -1.0f, float far = 1.0f);

		void setPosition(const glm::vec3& p) { position = p; RecalculateViewMatrix(); }
		void setRotation(float r) { rotation = r; RecalculateViewMatrix(); }

		const glm::vec3& getPosition() { return position; }
		float getRotation() { return rotation; }

		const glm::mat4& getProjectionMatrix() { return projection_matrix; }
		const glm::mat4& getViewMatrix() { return view_matrix; }
		const glm::mat4& getViewProjectionMatrix() { return viewprojection_matrix; }
	private:
		void RecalculateViewMatrix();
	};

} }