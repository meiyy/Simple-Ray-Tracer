#pragma once
#include <cmath>
template<class T>
class Vec2
{
public:
	T x[2];
	Vec2() {};
	Vec2(T x, T y) { this->x[0] = x; this->x[1] = y; };
	~Vec2() {};
	T innerProduct(Vec2<T> a);
	double module();
	Vec2<T>& norm();
	Vec2<T> operator-(Vec2<T> a);
	Vec2<T> operator+(Vec2<T> a);
	Vec2<T> operator*(T a);
	Vec2<T> operator/(T a);
};

template<class T>
inline Vec2<T> Vec2<T>::operator*(T a)
{
	Vec3<T> ans = *this;
	for (int i = 0; i < 2; i++)
	{
		ans.x[i] *= a;
	}
	return ans;
}

template<class T>
inline Vec2<T> Vec2<T>::operator/(T a)
{
	Vec3<T> ans = *this;
	for (int i = 0; i < 2; i++)
	{
		ans.x[i] /= a;
	}
	return ans;
}


template<class T>
double Vec2<T>::module()
{
	return (std::sqrt((double)x[0] * (double)x[0] + (double)x[1] * (double)x[1]));
}

template<class T>
Vec2<T>& Vec2<T>::norm()
{
	double tmp = this->module();
	for (int i = 0; i < 2; i++)
	{
		x[i] = (T)(x[i] / tmp);
	}
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::operator-(Vec2<T> a)
{
	Vec2<T> ans = *this;
	for (int i = 0; i < 2; i++)
	{
		ans.x[i] -= a.x[i];
	}
	return ans;
}

template<class T>
inline Vec2<T> Vec2<T>::operator+(Vec2<T> a)
{
	Vec2<T> ans = *this;
	for (int i = 0; i < 2; i++)
	{
		ans.x[i] += a.x[i];
	}
	return ans;
}

template<class T>
T Vec2<T>::innerProduct(Vec2<T> a)
{
	T ans = 0;
	for (int i = 0; i < 2; i++)
		ans += x[i] * a.x[i];
	return ans;
}
