#pragma once
#include "Vector2D.h"
#include "MovingObject.h"
#include "ColorPalette.h"
#include "ModelLoader.h"
// The player character. pos is the centre of its feet; the hitbox is
// width wide and height tall above that point.
class Player : public MovingObject
{
private:
	float height, width;
	int lives;
	bool can_jump; // true while standing on something
	int rot; // facing: -1 left, 0 towards the camera, 1 right
	ModelLoader model;

public:
	ColorPalette color;
	void Draw();
	Player(void);
	virtual ~Player(void);
	friend class Interact;
	float GetHeight();
	int GetLives();
	void SetLives(int lives);
	bool GetCanJump();
	void SetCanJump(bool can_jump);
	void SetRot(int rot);
	void DrawHitbox();
};
