#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

void initGrid(int x, int y)
{
	int gridX = x;
	int gridY = y;
}

void unit(int , int);

void drawGrid()
{
	unit(20, 20);
}

void unit(int x, int y)
{
	glLineWidth(1.0);
	glColor3f(1.0, 1.0, 1.0);
	
	glbegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x + 1, y);
		glVertex2f(x + 1, y + 1);
		glVertex2f(x, y + 1);
	glEnd();
}
