#pragma once
// 2D vector used for positions, velocities and accelerations in the XY
// plane of the game (X to the right, Y up).
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D(void);

	float x;
	float y;

	// Adds the scalar to x only
	Vector2D operator+(float scalar);

	float magnitude();

	// Angle from the X axis, in radians
	float angle();

	// Unit vector in the same direction (zero vector stays zero)
	Vector2D Unit();

	Vector2D operator-(const Vector2D &);

	Vector2D operator+(const Vector2D &);

	// Dot product
	float operator*(const Vector2D &);

	Vector2D operator*(float);
};
