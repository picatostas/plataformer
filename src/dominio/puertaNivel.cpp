#include "puertaNivel.h"
#include "glut.h"

puertaNivel::puertaNivel(float x1, float y1, float x2, float y2,float z1)
{
	limit1.x=x1;
	limit1.y=y1;
	limit2.x=x2;
	limit2.y=y2;
	z=z1;

}
puertaNivel::puertaNivel(void)
{
	color.Pink();
}
puertaNivel::~puertaNivel(void)
{
}
void puertaNivel::Draw()
{
	glDisable(GL_LIGHTING); 
	color.SetColor();
	glBegin(GL_POLYGON); 
		glVertex3d(8.0f,12,0);
		glVertex3d(8.0f,14,0); 
		glVertex3d(9.5f,14.0f,0);
		glVertex3d(9.5f,12,0); 
	glEnd();
	glEnable(GL_LIGHTING); 


}