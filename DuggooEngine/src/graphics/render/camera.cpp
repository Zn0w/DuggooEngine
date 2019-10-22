#include "camera.h"

#include "gtc/matrix_transform.hpp"


namespace dg { namespace graphics {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near = -1.0f, float far = 1.0f)
		: projection_matrix(glm::ortho(left, right, bottom, top, near, far)) 
	{
		
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transfrom = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), rotation, glm::vec3(0, 0, 1));
	}

} }