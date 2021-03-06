
#include "freeglut.h"
#include "CoordinadorJuego.h"

//los callback, funciones que seran llamadas automaticamente por glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);	 //esta funcion sera llamada para Draw
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecialKeyboardDown(int key, int x, int y);
void OnKeyboardUp(unsigned char key, int x, int y);
void OnKeyboardDown(unsigned char key, int x, int y);

CoordinadorJuego juego;
int main(int argc, char *argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Plataformer");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0); //le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutSpecialFunc(OnSpecialKeyboardDown); //gestion de los cursores

	//pasarle el control a GLUT, que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	juego.Draw();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	//poner aqui el codigo de keydo
	(void)x;
	(void)y;
	juego.KeyDown(key);
	juego.Key(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y)
{
	//Para la anulacion de velociadades cuando deje de pulsarse el keydo
	(void)x;
	(void)y;
	juego.KeyUp(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el codigo de animacion
	(void)value;
	juego.Move();
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x, int y)
{
	(void)x;
	(void)y;
	juego.KeyEspecial(key);
}
