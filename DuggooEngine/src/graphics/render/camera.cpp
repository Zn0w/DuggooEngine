#include "camera.h"

#include "gtc/matrix_transform.hpp"


namespace dg { namespace graphics {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far)
		: projection_matrix(glm::ortho(left, right, bottom, top, near, far)), view_matrix(1.0f)
	{
		viewprojection_matrix = projection_matrix * view_matrix;
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), rotation, glm::vec3(0, 0, 1));
		view_matrix = glm::inverse(transform);
		viewprojection_matrix = projection_matrix * view_matrix;
	}

} }