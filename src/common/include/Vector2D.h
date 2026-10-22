#pragma once
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D(void);

	float x;
	float y;

	Vector2D operator+(float scalar);

	float magnitude();

	float angle();

	Vector2D Unit();

	Vector2D operator-(const Vector2D &);

	Vector2D operator+(const Vector2D &);

	float operator*(const Vector2D &);

	Vector2D operator*(float);
};
