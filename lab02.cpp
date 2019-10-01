#include <GL/glut.h>
#include <stdlib.h>

static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

double cl1, cl2, cl3;

static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (cl1, cl2, cl3);
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();

    glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
     //store the x,y value where the click happened
     cl1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
     cl2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
     cl3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
     glColor3f (cl1, cl2, cl3);
     glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
     glEnd();

     glutSwapBuffers();
  }
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    cl1 = 1.0;
    cl2 = 0.25;
    cl3 = 1.0;
    glutDisplayFunc(display);
    glutMouseFunc(OnMouseClick);

    glutMainLoop();

    return EXIT_SUCCESS;
}

