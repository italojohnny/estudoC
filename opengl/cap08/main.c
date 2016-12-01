//gcc main.c -lglut -lGLU -lGL
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
const double meu_pi = 3.14159265359;
void Desenha (void)
{
glClearColor (0,0,0,0);                                                                                                                                                                                       
glClear (GL_COLOR_BUFFER_BIT);                                                                                                                                                                                   

glColor3f (1, 1, 1);                                                                                                                                                                                             
float ang;
glPointSize(1.0f);
glBegin (GL_POINTS);                                                                                                                                                                                          
	for (ang=0; ang< 2 * meu_pi; ang += meu_pi/10.0)
		glVertex2f(2.5*cos(ang), 2.5*sin(ang));
glEnd ();                                                                                                                                                                                                        

glFlush ();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27 || key == 'q') exit (0);
}

void Inicializa (void)
{
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-5.0, 5.0, -5.0, 5.0);
	glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char *argv[])
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutCreateWindow ("ExemploPonto2D");
	glutDisplayFunc (Desenha);
	glutKeyboardFunc (Teclado);
	Inicializa ();
	glutMainLoop ();
	return 0;
}
