#include "matrix.h"

namespace dg { namespace math {

	Matrix4::Matrix4()
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;
	}

	Matrix4::Matrix4(float diagonalElement)
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;

		elements[4 * 0 + 0] = diagonalElement;
		elements[4 * 1 + 1] = diagonalElement;
		elements[4 * 2 + 2] = diagonalElement;
		elements[4 * 3 + 3] = diagonalElement;
	}

	Matrix4 identity()
	{
		return Matrix4(1.0f);
	}

	Matrix4 multiply(Matrix4 m1, Matrix4 m2)
	{
		Matrix4 m;
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				float sum = 0.0f;

				for (int e = 0; e < 4; e++)
				{
					sum += m1.elements[4 * i + e] * m2.elements[4 * e + j];
				}

				m.elements[4 * i + j] = sum;
			}
		}

		return m;
	}

	bool equals(Matrix4 m1, Matrix4 m2)
	{
		for (int i = 0; i < 16; i++)
			if (m1.elements[i] != m2.elements[i])
				return false;

		return true;
	}

} }