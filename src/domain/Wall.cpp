#include "Wall.h"
#include "glut.h"
#include "Bitmap.h"
#include "TextureContainer.h"
#include <iostream>
Wall::Wall(void)
{
}
Wall::Wall(char *texture)
{
	this->texture = texture;
}

Wall::~Wall(void)
{
}

Wall::Wall(float x1, float y1, float x2, float y2, float z1, bool is_front, ColorPalette color)
{
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
	z = z1;
	this->is_front = is_front;
	this->color = color;
}

void Wall::SetPos(float x1, float y1, float x2, float y2, float z1, bool is_front)
{
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
	z = z1;
	this->is_front = is_front;
}
void Wall::LoadTexture(std::string texture)
{
	this->texture = texture;
}

void Wall::Draw()
{
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor3ub(color.r, color.g, color.b);

	TextureContainer &container = TextureContainer::GetInstance();
	Bitmap *texture_obj = container.GetTexture(texture);
	if (texture_obj != nullptr)
	{
		texture_obj->ApplyTexture();
	}
	else
	{
		std::cout << " got nullptr instead of Bitmap * trying to get " << texture << std::endl;
	}
	glBegin(GL_QUADS);
	// To draw a front panel
	if (is_front)
	{
		glTexCoord2f(0.0, 0.0);
		glVertex3f(limit1.x, limit1.y, z);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(limit1.x, limit2.y, z);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(limit2.x, limit2.y, z);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(limit2.x, limit1.y, z);
	}
	// To draw a normal plane to the front panel
	else
	{
		glTexCoord2f(0.0, 0.0);
		glVertex3d(limit1.x, limit1.y, z);
		glTexCoord2f(0.0, 1.0);
		glVertex3d(limit2.x, limit2.y, z);
		glTexCoord2f(1.0, 1.0);
		glVertex3d(limit2.x, limit2.y, -z);
		glTexCoord2f(1.0, 0.0);
		glVertex3d(limit1.x, limit1.y, -z);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}

// Distance from a wall to a point. Additionally, the optional direction
// vector is set to the outgoing unit vector that points along the
// shortest line between the point and the wall.
float Wall::Distance(Vector2D point, Vector2D *direction)
{
	Vector2D u = (point - limit1);
	Vector2D v = (limit2 - limit1).Unit();
	float length = (limit1 - limit2).magnitude();
	Vector2D dir;
	float projection = u * v;
	float distance = 0.0f;

	if (projection < 0.0f)
		dir = u;
	else if (projection > length)
		dir = (point - limit2);
	else
		dir = u - v * projection;
	distance = dir.magnitude();
	if (direction != 0) // if a vector was provided
		*direction = dir.Unit();
	return distance;
}
