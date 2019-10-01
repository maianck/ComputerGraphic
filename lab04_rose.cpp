#include <GL/glut.h>
#include <math.h>

float x,y;
float k = 1.0, pi = 3.14;
float len = 0.5;
int n = 4;

void display(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINE_STRIP);
	 glColor3f(1.0, 0.0, 1.0);
	 float fi = 0;
	 while(fi<=2*pi*n) {
        x = len*cos(fi)*k*cos(n*fi), y = len*sin(fi)*k*cos(n*fi);
        glVertex2f(x, y);
        fi+=n*0.0005;
	 }

	 glEnd();
	 glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rose");
    glutDisplayFunc(display);
    glutMainLoop();
}

