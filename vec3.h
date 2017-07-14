#pragma once
#include <cmath>
template<class T>
class Vec3
{
public:
	T x[3];
	Vec3() {};
	Vec3(T x, T y, T z) { this->x[0] = x; this->x[1] = y; this->x[2] = z; };
	~Vec3() {};
	T innerProduct(Vec3<T> a);
	Vec3<T> outerProduct(Vec3<T> a);
	double module();
	Vec3<T>& norm();
	Vec3<T> operator-(Vec3<T> a);
	Vec3<T> operator+(Vec3<T> a);
};

template<class T>
Vec3<T> Vec3<T>::outerProduct(Vec3<T> a)
{
	Vec3<T> ans;
	ans.x[0] = x[1] * a.x[2] - x[2] * a.x[1];
	ans.x[1] = x[2] * a.x[0] - x[0] * a.x[2];
	ans.x[2] = x[0] * a.x[1] - x[1] * a.x[0];
	return ans;
}

template<class T>
double Vec3<T>::module()
{
	return (std::sqrt((double)x[0] * (double)x[0] + (double)x[1] * (double)x[1] + (double)x[2] * (double)x[2]));
}

template<class T>
Vec3<T>& Vec3<T>::norm()
{
	double tmp = this->module();
	for (int i = 0; i < 3; i++)
	{
		x[i] = (T)(x[i] / tmp);
	}
	return *this;
}

template<class T>
inline Vec3<T> Vec3<T>::operator-(Vec3<T> a)
{
	Vec3<T> ans = *this;
	for (int i = 0; i < 3; i++)
	{
		ans.x[i] -= a.x[i];
	}
	return ans;
}

template<class T>
inline Vec3<T> Vec3<T>::operator+(Vec3<T> a)
{
	Vec3<T> ans = *this;
	for (int i = 0; i < 3; i++)
	{
		ans.x[i] += a.x[i];
	}
	return ans;
}

template<class T>
T Vec3<T>::innerProduct(Vec3<T> a)
{
	T ans = 0;
	for (int i = 0; i < 3; i++)
		ans += x[i] * a.x[i];
	return ans;
}
