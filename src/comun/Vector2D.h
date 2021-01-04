#pragma once
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D(void);

	float x;
	float y;

	Vector2D operator+(Vector2D op);

	Vector2D operator+(float real);

	float modulo();

	float argumento();

	Vector2D Unitario();

	Vector2D operator-(Vector2D &);

	Vector2D operator+(Vector2D &);

	float operator*(Vector2D &);

	Vector2D operator*(float);
};
