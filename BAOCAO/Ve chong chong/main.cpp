#include<glut.h>
GLfloat anpha=0; 
void init() { 
	glClearColor (1.0, 0.0, 0.0, 1.0); //
	glColor3f(1.0, 1.0, 1.0); 
	glMatrixMode (GL_PROJECTION); 
	glLoadIdentity (); 
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
	} 
void mydisplay() { 
	glClear(GL_COLOR_BUFFER_BIT); 
	glPushMatrix(); //Quay chong chóng 
	glRotatef(anpha, 0, 0, 1); //V? chong chóng 
	glPushMatrix(); 
	for(int i=1;i<=4;i++) { 
	if (i==1) glColor3f(0, 1, 0); 
	if (i==2) glColor3f(0, 0, 1); 
	if (i==3) glColor3f(1, 1, 0); 
	if (i==4) glColor3f(0, 1, 1); 
	glBegin(GL_POLYGON); 
	glVertex3f(0.0, 0.5,0.0); 
	glVertex3f(0.15, 0.2, 0.0); 
	glVertex3f(0.0, 0.0, 0.0); 
	glEnd(); glRotatef(90,0,0,1); 
	} 
	glPopMatrix(); //K?t thúc v? chong chóng 
	glPopMatrix(); //K?t thúc quay chong chóng 
	glutSwapBuffers(); 
} 
void timer(int v) { 
	anpha+=10; 
	if (anpha>360) 
		anpha=0; 
	glutTimerFunc(50, timer,v); 
	glutPostRedisplay(); 
} 
int main(int argc, char** argv) { 
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
	glutInitWindowSize(500,500); 
	glutInitWindowPosition(0,0); 
	glutCreateWindow("simple"); 
	init();
	glutDisplayFunc(mydisplay); 
	timer(0); 
	glutMainLoop(); 
}
