#pragma once
#include <cmath>
template<class T>
class Vec3
{
public:
	T x[3];
	Vec3() {};
	Vec3(Vec3<T> &&a)
	{
		x[0] = a.x[0];
		x[1] = a.x[1];
		x[2] = a.x[2];
	}
	Vec3(Vec3<T> &a)
	{
		x[0] = a.x[0];
		x[1] = a.x[1];
		x[2] = a.x[2];
	}
	Vec3(T x, T y, T z) { this->x[0] = x; this->x[1] = y; this->x[2] = z; };
	Vec3<T> operator=(Vec3<T> &&a)
	{
		x[0] = a.x[0];
		x[1] = a.x[1];
		x[2] = a.x[2];
		return *this;
	}
	Vec3<T> operator=(Vec3<T> &a)
	{
		x[0] = a.x[0];
		x[1] = a.x[1];
		x[2] = a.x[2];
		return *this;
	}
	~Vec3() {};
	T innerProduct(const Vec3<T> &a)const;
	Vec3<T> outerProduct(const Vec3<T> &a)const;
	double module()const;
	Vec3<T>& norm();
	Vec3<T> operator-(const Vec3<T> &a)const;
	Vec3<T> operator+(const Vec3<T> &a)const;
	Vec3<T> operator*(T a)const;
	Vec3<T> operator/(T a)const;
};

template<class T>
inline Vec3<T> Vec3<T>::outerProduct(const Vec3<T> &a)const
{
	Vec3<T> ans;
	ans.x[0] = x[1] * a.x[2] - x[2] * a.x[1];
	ans.x[1] = x[2] * a.x[0] - x[0] * a.x[2];
	ans.x[2] = x[0] * a.x[1] - x[1] * a.x[0];
	return ans;
}

template<class T>
inline double Vec3<T>::module()const
{
	return (std::sqrtl(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]));
}

template<class T>
inline Vec3<T>& Vec3<T>::norm()
{
	double tmp = this->module();
	x[0] /= tmp;
	x[1] /= tmp;
	x[2] /= tmp;
	return *this;
}

template<class T>
inline Vec3<T> Vec3<T>::operator-(const Vec3<T> &a)const
{
	return Vec3<T>(x[0] - a.x[0], x[1] - a.x[1], x[2] - a.x[2]);
}

template<class T>
inline Vec3<T> Vec3<T>::operator+(const Vec3<T> &a)const
{
	return Vec3<T>(x[0] + a.x[0], x[1] + a.x[1], x[2] + a.x[2]);
}

template<class T>
inline Vec3<T> Vec3<T>::operator*(T a)const
{
	return Vec3<T>(x[0] * a, x[1] * a, x[2] * a);
}

template<class T>
inline Vec3<T> Vec3<T>::operator/(T a)const
{
	return Vec3<T>(x[0] / a, x[1] / a, x[2] / a);
}

template<class T>
inline T Vec3<T>::innerProduct(const Vec3<T> &a)const
{
	return x[0] * a.x[0] + x[1] * a.x[1] + x[2] * a.x[2];
}
