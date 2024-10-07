#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float squareX = 0.0f;
float squareY = 0.0f;
float squareZ = 0.0f;

static int flag = 1;

void drawShape(void) {
    glTranslatef(squareX, squareY, squareZ); 
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(162, 50);
    glVertex2f(162, 10);
    glVertex2f(220, 10);
    glVertex2f(220, 50);
    glVertex2f(162, 50);
    glEnd();
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 

    glOrtho( 0.0f, (float)w, 0.0f,(float)h, -3.0f, 3.0f );
}  

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawShape();
    glutSwapBuffers();
}

void update(int value) {
    if (flag) {
        squareY += 3.0f;
        if (squareY > 350.0) {
            flag = 0;
        }
    }
    if (!flag) {
        squareY -= 3.0f;
        if (squareY < 0.0) {
            flag = 1;
        }
    }
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Moving Square");
    initRendering();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return(0);
}