#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/GL.h>
#include <iostream>

using namespace std;

const int WIDTH = 700 , HEIGHT = 700;

static double xspeed = 0.0 , yspeed = 0.0 , zspeed = 0.0 ;

bool zstop = false , xstop = false , ystop = false , polymod = false ;

bool optocons = true;

float rotonx, rotony , rotonz, speed = 0.1;

// variables used for the light source and position.
GLfloat frontamdiff[] = {0.7 , 0.5, 0.1 , 1.0};
GLfloat amb[] = {0.3 , 0.3, 0.3 , 0.1};
GLfloat pos[] = {-3 , 3, 8 , 1};


void yrotating (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(-2.5,2.5,-10.0);
    glRotatef(rotony,0.0,1.0,0.0);

}

void xrotating1 (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(2.5,2.5,-10.0);
    glRotatef(rotonx,1.0,0.0,0.0);

}

void xrotating2 (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(2.5,-2.5,-10.0);
    glRotatef(rotonx,-1.0,0.0,0.0);

}

void zrotating (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(-2.5,-2.5,-10.0);
    glRotatef(rotonz,0.0,0.0,1.0);

}

void anchors(){

	glBegin( GL_QUADS );
	// right anchor
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( 1.0 , -0.1 , 0.1 ); glVertex3f( 2.0 , -0.1 , 0.1 );
	glVertex3f( 2.0 , 0.1 , 0.1 ); glVertex3f( 1.0 , 0.1 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( 1.0 , -0.1 , -0.1 ); glVertex3f( 2.0 , -0.1 , -0.1 );
	glVertex3f( 2.0 , 0.1 , -0.1 ); glVertex3f( 1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( 1.0 , 0.1 , 0.1 ); glVertex3f( 2.0 , 0.1 , 0.1 );
	glVertex3f( 2.0 , 0.1 , -0.1 ); glVertex3f( 1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( 1.0 , -0.1 , 0.1 ); glVertex3f( 2.0 , -0.1 , 0.1 );
	glVertex3f( 2.0 , -0.1 , -0.1 ); glVertex3f( 1.0 , -0.1 , -0.1 );

	// left anchor
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( -1.0 , -0.1 , 0.1 ); glVertex3f( -2.0 , -0.1 , 0.1 );
	glVertex3f( -2.0 , 0.1 , 0.1 ); glVertex3f( -1.0 , 0.1 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( -1.0 , -0.1 , -0.1 ); glVertex3f( -2.0 , -0.1 , -0.1 );
	glVertex3f( -2.0 , 0.1 , -0.1 ); glVertex3f( -1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( -1.0 , 0.1 , 0.1 ); glVertex3f( -2.0 , 0.1 , 0.1 );
	glVertex3f( -2.0 , 0.1 , -0.1 ); glVertex3f( -1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( -1.0 , -0.1 , 0.1 ); glVertex3f( -2.0 , -0.1 , 0.1 );
	glVertex3f( -2.0 , -0.1 , -0.1 ); glVertex3f( -1.0 , -0.1 , -0.1 );

	glColor3f( 0.7 , 0.0 , 0.0);

	glEnd();

}

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0,0.0,-10.0 );
	
	zrotating();
	anchors();
	glColor3f( 0.7 , 0.0 , 0.0);
	glutSolidTorus( 0.3 , 1.0 , 20 , 50);
	glPopMatrix();
	
	xrotating1();
	anchors();
	glColor3f( 0.0 , 0.7 , 0.0);
	glutSolidTorus( 0.3 , 1.0 , 20 , 50);
	glPopMatrix();
	
	
	xrotating2();
	anchors();
	glColor3f( 0.0 , 0.7 , 0.0);
	glutSolidTorus( 0.3 , 1.0 , 20 , 50);
	glPopMatrix();


	yrotating();
	anchors();
	glColor3f( 0.0 , 0.0 , 0.7);
	glutSolidTorus( 0.3 , 1.0, 20 , 50);
	glPopMatrix();
	
	glutSwapBuffers();

}

void idletor(void){
	 
	if( zstop == true);		
	else
		rotonz += speed;

	if( ystop == true);		
	else
		rotony += speed;

	if(xstop == true);
	else
		rotonx += speed;

	glutPostRedisplay();


}

void keyboard(unsigned char key, int kbx, int kby){
	switch(key){
		case 'x':
			xstop = !xstop;
			break;

		case 'y':
			ystop = !ystop;
			break;

		case 'z':
			zstop = !zstop;
			break;
	}

	glutPostRedisplay();

}

void consolecmd(){
	if( optocons == true){
		cout << "TO STOP THE RINGS:	X to stop xrotation	::	Y to stop yrotation ::	Z to stop zrotation \n";
		cout << "please enter the speed of rotation : ";
		cin >> speed;
		optocons = false;
	}
}

int main(int argc, char* argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(200,100);

	glutCreateWindow("project 2");
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	
	glOrtho(-5.0 , 5.0 , -5.0 , 5.0 , 5 , 20);

	glMaterialf(GL_FRONT, GL_AMBIENT , 1.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT , amb);
	glLightModeli(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0,0,-5);
	glLightfv(GL_LIGHT0 , GL_POSITION , pos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idletor);

	consolecmd();
	glutMainLoop();
	return 0;
 
}