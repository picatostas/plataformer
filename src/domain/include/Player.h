#pragma once
#include "Vector2D.h"
#include "MovingObject.h"
#include "ColorPalette.h"
#include "ModelLoader.h"
class Player : public MovingObject
{
private:
	float height, width;
	int lives;
	bool can_jump;
	int rot;
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
