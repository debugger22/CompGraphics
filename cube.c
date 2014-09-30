/*
* This file demonstrates rendering of a wired cube.
*/

#include <stdlib.h>
#include <GL/glut.h>

void init(void)
{
   glClearColor (0.9, 0.3, 0.1, 0.0);  // Setting background color
   glShadeModel (GL_FLAT);
}


void mDisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);  // Setting fill color
   glLoadIdentity();
   gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Setting the view camera
   glutWireCube(1.5);  // Drawing the wire cube scaled at 150%
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
