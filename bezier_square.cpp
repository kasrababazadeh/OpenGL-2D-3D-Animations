
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float squareX = 0.0f;
float squareY = -0.3f;
float squareZ = 0.0f;
float time = 0.0;
float timeInterval = 0.005;
static int flag = 1;
float controlPointsGirl[4][2] = {
        { 100, 100}, { 2000, 6000}, 
        {4000, 300}, {11000, 7000}};

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

// safhe resize shodani seda zade mishe
void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    
    glOrtho( 0.0f, (float)w, 0.0f,(float)h, -1.0f, 1.0f );
}  

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawShape();
    glutSwapBuffers();
}


void update(int value) {

    squareX = ((1 - time)*(1 - time)*(1 - time)*controlPointsGirl[0][0]
    + (3 * time*(1 - time)*(1 - time))* controlPointsGirl[1][0]
    + (3 * time*time*(1 - time))* controlPointsGirl[2][0]
    + time*time*time*controlPointsGirl[3][0])
    /10;


	squareY = ((1 - time)*(1 - time)*(1 - time)*controlPointsGirl[0][1]
    + (3 * time*(1 - time)*(1 - time))* controlPointsGirl[1][1]
    + (3 * time*time*(1 - time))* controlPointsGirl[2][1]
    + time*time*time*controlPointsGirl[3][1])
    /10;


	time += timeInterval;
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