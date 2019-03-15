#pragma once

namespace dg { namespace math {
	
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float, float);
	};

	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(float, float, float);
	};

	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(float, float, float, float);
	};

	Vector2 add(Vector2, Vector2);
	Vector3 add(Vector3, Vector3);
	Vector4 add(Vector4, Vector4);
	
	Vector2 subtract(Vector2, Vector2);
	Vector3 subtract(Vector3, Vector3);
	Vector4 subtract(Vector4, Vector4);
	
	Vector2 multiply(Vector2, Vector2);
	Vector3 multiply(Vector3, Vector3);
	Vector4 multiply(Vector4, Vector4);
	
	Vector2 divide(Vector2, Vector2);
	Vector3 divide(Vector3, Vector3);
	Vector4 divide(Vector4, Vector4);

	bool equals(Vector2, Vector2);
	bool equals(Vector3, Vector3);
	bool equals(Vector4, Vector4);

} }