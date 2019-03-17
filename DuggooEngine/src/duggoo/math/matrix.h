#pragma once

#include "vector.h"

namespace dg { namespace math {

	struct Matrix4
	{
		float elements[4][4];

		Matrix4();

		Matrix4(float diagonalElement);
	};

	Matrix4 mutliply(Matrix4, Matrix4);
	bool equals(Matrix4, Matrix4);
	
	// Objects (or their parts) that are not in the window boundaries, behind the camera (too near) and too far away will
	// not be drawn
	Matrix4 orthographic(float left, float right, float negative, float positive, float near, float far);

	// Objects (or their parts) are drawn in the cameras field of view (fox) and will be smaller far away and bigger near
	// the camera
	Matrix4	perspective(float fov, float aspectRatio, float near, float far);

	// Move from one place to another
	Matrix4 translation(Vector3 translation);

	// Turn about a fixed point (origin) a fixed angle
	Matrix4 rotation(float angle, Vector3 axis);

	Matrix4 scale(Vector3);

} }