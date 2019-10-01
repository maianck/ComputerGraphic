#include <GL/glut.h>
#include <math.h>

float startX=-0.7,startY=0.5;
float pi = 3.14;

void drawkoch(float dir, float len, int iter) {
	double dirRad = (pi/180) * dir;
	float newX = startX + len * cos(dirRad);
	float newY = startY + len * sin(dirRad);
	if (iter==0) {
		glVertex2f(startX, startY);
		glVertex2f(newX, newY);
		startX = newX;
		startY = newY;
	}
	else {
		iter--;
		//draw the four parts of the side _/\_
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
		dir -= 120.0;
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
	}
}

void display(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(0.0, 0.0, 1.0); // make it blue

	 //call drawkoch 3 times, one for each side of the triangle, changing direction each time
	 drawkoch(0.0,0.05,3);
	 drawkoch(-120.0, 0.05, 3);
	 drawkoch(120.0,0.05,3);

	 glEnd();
	 glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Koch Snowflake");
	glutDisplayFunc(display);
	glutMainLoop();
}
