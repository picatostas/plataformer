#include "Player.h"
#include "glut.h"

Player::Player(void)
{
	height = 2.0f;
	width = 1.0f;
	accel.y = -20.8f;
	lives = 3;
	can_jump = false;
	model.Load("models/birdman.obj");
	rot = 0;
}

Player::~Player(void)
{
}
void Player::Draw()
{
	glDisable(GL_LIGHTING);
	if (lives >= 3)
		color = ColorPalette::Lime();
	else if (lives == 2)
		color = ColorPalette::Orange();
	else if (lives == 1)
		color = ColorPalette::Red();
	else if (lives == 0)
		color = ColorPalette::Brown();

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);

#ifdef DEBUG
	DrawHitbox();
#endif

	glColor3ub(color.r, color.g, color.b);
	glPushMatrix();
	glScalef(0.06f, 0.06f, 0.06f);
	glRotatef(-180, 0, 1, 0);
	if (lives == 0)
	{
		// If player died, turn its body as if it fell
		glTranslatef(0, 12, 0);
		glRotatef(-90, 0, 0, 1);
	}
	if (rot != 0)
	{
		glRotatef(90, 0, 1 * rot, 0);
	}
	model.Draw();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}
void Player::DrawHitbox()
{
	glPushMatrix();
	glTranslatef(-width / 2, 0, 0);
	ColorPalette hitbox_color = ColorPalette::Yellow();
	glColor3ub(hitbox_color.r, hitbox_color.g, hitbox_color.b);
	// TODO: Implement this only Giving vertex and not specifying every single wire
	glBegin(GL_LINES);
	// Base
	glVertex3f(0, 0, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, 0, width);
	glVertex3f(width, 0, width);
	glVertex3f(0, 0, width);
	glVertex3f(0, 0, width);
	glVertex3f(0, 0, 0);
	// roof
	glVertex3f(0, height, 0);
	glVertex3f(width, height, 0);
	glVertex3f(width, height, 0);
	glVertex3f(width, height, width);
	glVertex3f(width, height, width);
	glVertex3f(0, height, width);
	glVertex3f(0, height, width);
	glVertex3f(0, height, 0);
	// vertical wires
	glVertex3f(0, 0, 0);
	glVertex3f(0, height, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, height, 0);
	glVertex3f(width, 0, 0);
	glVertex3f(width, height, 0);
	glVertex3f(width, 0, width);
	glVertex3f(width, height, width);
	glVertex3f(0, 0, width);
	glVertex3f(0, height, width);
	glVertex3f(0, 0, 0);
	glVertex3f(0, height, 0);
	glEnd();
	glPopMatrix();
}

float Player::GetHeight()
{
	return height;
}

void Player::SetLives(int lives)
{
	this->lives = lives;
}
int Player::GetLives()
{

	return lives;
}
bool Player::GetCanJump()
{
	return can_jump;
}
void Player::SetCanJump(bool can_jump)
{
	this->can_jump = can_jump;
}
void Player::SetRot(int rot)
{
	if (rot >= -1 && rot <= 1)
		this->rot = rot;
}
