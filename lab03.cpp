#include <GL/glut.h>
#include <stdlib.h>

double d = 1;
double t = 0;
double m[9][2];

static void display(void)
{
    double StartShape[9][2] = {{0, 10},
                              {-25, 10},
                              {-25, 0},
                              {-5, 0},
                              {-5, -20},
                              {5, -20},
                              {5, 0},
                              {25, 0},
                              {25, 10}};
    double EndShape[9][2] = {
        {-25, 10},
        {-25, -20},
        {-5, -20},
        {-5, -10},
        {5, -10},
        {5, -20},
        {25, -20},
        {25, 10},
        {0, 20} };
    for (int i = 0; i < 9; ++i) {
        m[i][0] = (1 -t) * StartShape[i][0] + t * EndShape[i][0];
        m[i][1] = (1 -t) * StartShape[i][1] + t * EndShape[i][1];
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP, 0, 9);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 9; i++)
    {
        glVertex2d(m[i][0], m[i][1]);
    }
    t += 0.0001 * d;
    if(t>=1&&d>=1) d=-1;
    if(t<=0&&d<=-1) d=1;
    glEnd();
    glutSwapBuffers();
    glutPostRedisplay();
}

void init (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    glOrtho(-30, 30.0, -30.0, 30.0, -1.0, 1.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(150,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );

    glutCreateWindow("lab03");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

