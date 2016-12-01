/*
 * Compilar em linux:
 * gcc main.c -lglut -lGLU -lGL
 *
 * Compilar em windows:
 * gcc main.c -lglut32cu -lglu32 -lopengl32
 *
 */
#define LINUX //comente essa linha em caso de complilação para windows
#include <stdlib.h>
#include <GL/glut.h>

void Desenha (void);
void Teclado (unsigned char, int, int);
void Inicializa (void);

int main (int argc, char *argv[])
{
#ifdef LINUX
	glutInit (&argc, argv);
#endif
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutCreateWindow ("Primeiro Programa");
	glutDisplayFunc (Desenha);
	glutKeyboardFunc (Teclado);
	
	Inicializa ();

	glutMainLoop ();

	return 0;
}

void Desenha (void)
{
	glClearColor (1, 1, 1, 0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	glColor3f (1, 0, 0);

	glBegin (GL_TRIANGLES);
		glVertex3f (-0.5, -0.5, 0);
		glVertex3f ( 0.0,  0.5, 0);
		glVertex3f ( 0.5, -0.5, 0);
	glEnd ();

	glFlush ();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27) exit (0);
}

void Inicializa (void)
{
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-1.0, 1.0, -1.0, 1.0);
	glMatrixMode (GL_MODELVIEW);
}
