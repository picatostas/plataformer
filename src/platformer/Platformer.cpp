
#include "freeglut.h"
#include "GameCoordinator.h"

// Callbacks: functions that GLUT calls automatically when events happen.
// THERE IS NO NEED TO CALL THEM EXPLICITLY
void OnDraw(void);	 // called to draw the scene
void OnTimer(int value); // called when a timer expires
void OnKeyboardDown(unsigned char key, int x, int y);
void OnKeyboardUp(unsigned char key, int x, int y);

GameCoordinator game;
int main(int argc, char *argv[])
{
	// Initialize the GLUT window manager
	// and create the window
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Platformer");

	// enable lighting and set up the perspective
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	// Register the callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0); // call OnTimer() once, 25ms from now
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);

	// hand control to GLUT, which will call the callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set up the point of view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	game.Draw();

	// do not remove this line or put anything after it
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	// keyboard handling code goes here
	(void)x;
	(void)y;
	game.KeyDown(key);
	game.Key(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y)
{
	// Cancel velocities when the key is released
	(void)x;
	(void)y;
	game.KeyUp(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	// animation code goes here
	(void)value;
	game.Move();
	// do not remove these lines
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
