/* Bresenhams Line Drawing Algorithm */
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
int x00, y00, xEnd, yEnd;

void display()
{
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	void line(x00, y00, xEnd, yEnd);
	glFlush();
}

void drawPixel(int x, int y)
{
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void line(int x00, int y00, int xEnd, int yEnd)
{
	int dx = fabs(xEnd - x00), dy = fabs(yEnd - y00);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy - dx, twoDyMinusDx = 2 * (dy - dx);
	int x, y;

	/*Determine which endpoint to use as starting position*/

	if (x00 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x00;
	} else {
		x = x00;
		y = y00;
	}

	drawPixel(x, y);

	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}

		drawPixel(x, y);
	}
}

void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 950.0, 0.0, 950.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	printf("Enter two end points of the line");
	scanf("%d %d %d %d", &x00, &y00, &xEnd, &yEnd);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("BRESENHAM'S LINE DRAWING ALGORITHM");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
