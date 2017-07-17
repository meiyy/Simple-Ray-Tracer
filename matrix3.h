#pragma once
template<class T>
class Matrix3
{
public:
	T data[3][3];
	Matrix3() {}
	Matrix3(T x[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				data[i][j] = x[i][j];
			}
		}
	}
	T det()
	{
		return data[0][0] * data[1][1] * data[2][2]
			+ data[0][1] * data[1][2] * data[2][0]
			+ data[0][2] * data[1][0] * data[2][1]
			- data[0][0] * data[1][2] * data[2][1]
			- data[0][1] * data[1][0] * data[2][2]
			- data[0][2] * data[1][1] * data[2][0];
	}
	Matrix3<T> operator*(const Matrix3<T> &a)
	{
		Matrix3<T> ans;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					ans.data[i][j] += data[i][k] * a.data[k][j];
				}
			}
		}
		return ans;
	}
	~Matrix3() {}
};

