#include "math.h"
#include "Vector2D.h"

Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

Vector2D::~Vector2D(void)
{
}

Vector2D Vector2D::operator+(float scalar)
{
	Vector2D result;

	result.x = x + scalar;
	result.y = y;
	return result;
}

float Vector2D::magnitude()
{
	return (float)sqrt(x * x + y * y);
}

float Vector2D::angle()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::Unit()
{
	Vector2D result(x, y);
	float mag = magnitude();

	if (mag > 0.0f)
	{
		result.x /= mag;
		result.y /= mag;
	}

	return result;
}

Vector2D Vector2D::operator-(const Vector2D &v)
{
	Vector2D res;

	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator+(const Vector2D &v)
{
	Vector2D res;

	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector2D::operator*(const Vector2D &v)
{
	float res;

	res = (x * v.x) + (y * v.y);
	return res;
}

Vector2D Vector2D::operator*(float scalar)
{
	Vector2D res;

	res.x = (x * scalar);
	res.y = (y * scalar);
	return res;
}
