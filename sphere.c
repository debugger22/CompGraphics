/*
* This file demonstrates rendering of a wired sphere.
*/


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float radius;

void init(void)
{
   glClearColor(0.9, 0.3, 0.1, 0.0);  // Setting background color
   glShadeModel(GL_SMOOTH);
}

void mDisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);  // Setting fill color
   glLoadIdentity ();
   gluLookAt(4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Setting the view camera
   glutWireSphere(radius, 40, 40);  // Drawing the wire sphere
   glFlush();
}

void mReshape (int w, int h){
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
   printf("Enter the radius of the sphere: ");
   scanf("%f", &radius);
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (650, 650);
   glutInitWindowPosition (400, 30);
   glutCreateWindow ("Draw cube");
   init ();
   glutDisplayFunc(mDisplay);
   glutReshapeFunc(mReshape);
   glutMainLoop();
   return 0;
}
