
#include "freeglut.h"
#include "GameCoordinator.h"

// GLUT callbacks; GLUT calls these when the window needs drawing, the
// timer fires or a key is pressed/released.
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnKeyboardUp(unsigned char key, int x, int y);

// Global so the GLUT callbacks can reach it
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
	glutTimerFunc(25, OnTimer, 0); // OnTimer() re-arms itself every 25 ms
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

	// Show the frame that was just drawn (double buffering)
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	game.KeyDown(key);
	game.Key(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	game.KeyUp(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	(void)value;
	game.Move();
	// Schedule the next step and redraw
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
