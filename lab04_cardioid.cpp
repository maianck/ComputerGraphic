#include <GL/glut.h>
#include <math.h>

float startX;
float startY;
float k = 0.5, pi = 3.14;
float len = 0.5;

void display(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINE_STRIP);
	 glColor3f(1.0, 0.0, 1.0);
	 for(int i = 360; i>=0; --i) {
        float fi = (pi/180)*i;
        startX = len*cos(fi)*k*(1+ cos(fi)), startY = len*sin(fi)*k*(1+ cos(fi));
        glVertex2f(startX, startY);
	 }
	 glEnd();
	 glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Cardioid");
    glutDisplayFunc(display);
    glutMainLoop();
}
