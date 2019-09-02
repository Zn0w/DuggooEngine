#pragma once

#include "vector.h"

namespace dg { namespace math {

	// Vector 2D
	
	Vector2::Vector2()
	{
		
	}

	Vector2::Vector2(float xValue, float yValue)
	{
		x = xValue;
		y = yValue;
	}

	Vector2 add(Vector2 v1, Vector2 v2)
	{
		Vector2 vector(v1.x + v2.x, v1.y + v2.y);
		return vector;
	}

	Vector2 subtract(Vector2 v1, Vector2 v2)
	{
		Vector2 vector(v1.x - v2.x, v1.y - v2.y);
		return vector;
	}
	
	Vector2 multiply(Vector2 v1, Vector2 v2)
	{
		Vector2 vector(v1.x * v2.x, v1.y * v2.y);
		return vector;
	}
	
	Vector2 divide(Vector2 v1, Vector2 v2)
	{
		Vector2 vector(v1.x / v2.x, v1.y / v2.y);
		return vector;
	}

	bool equals(Vector2 v1, Vector2 v2)
	{
		return v1.x == v2.x && v1.y == v2.y;
	}


	// Vector 3D

	Vector3::Vector3()
	{

	}

	Vector3::Vector3(float xValue, float yValue, float zValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
	}

	Vector3 add(Vector3 v1, Vector3 v2)
	{
		Vector3 vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		return vector;
	}

	Vector3 subtract(Vector3 v1, Vector3 v2)
	{
		Vector3 vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		return vector;
	}

	Vector3 multiply(Vector3 v1, Vector3 v2)
	{
		Vector3 vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
		return vector;
	}

	Vector3 divide(Vector3 v1, Vector3 v2)
	{
		Vector3 vector(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
		return vector;
	}

	bool equals(Vector3 v1, Vector3 v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}


	// Vector 4D

	Vector4::Vector4()
	{

	}

	Vector4::Vector4(float xValue, float yValue, float zValue, float wValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
		w = wValue;
	}

	Vector4 add(Vector4 v1, Vector4 v2)
	{
		Vector4 vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
		return vector;
	}

	Vector4 subtract(Vector4 v1, Vector4 v2)
	{
		Vector4 vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
		return vector;
	}

	Vector4 multiply(Vector4 v1, Vector4 v2)
	{
		Vector4 vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
		return vector;
	}

	Vector4 divide(Vector4 v1, Vector4 v2)
	{
		Vector4 vector(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
		return vector;
	}

	bool equals(Vector4 v1, Vector4 v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
	}

} }