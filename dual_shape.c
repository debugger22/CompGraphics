/*
* This file demonstrates rendering of different kind of shapes
*
* Press 's' to draw sphere
* Press 'c' to draw cylinder
* Press '+/-' to zoom in/out
* press 'w' to switch between wired and solid structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


float radius = 1.4;
float radius_cyl = 0.5;

int WireFrameOn = 1;

int DRAW_CYLINDER = GL_FALSE;  // Shape identifier boolean

void mKeyboardFunc(unsigned char key, int x, int y){
   switch (key) {
      case 'w':
         WireFrameOn = 1 - WireFrameOn;
         glutPostRedisplay();
         break;

      case 'c':
         DRAW_CYLINDER = GL_TRUE;
         glutPostRedisplay();
         break;

      case 's':
         DRAW_CYLINDER = GL_FALSE;
         glutPostRedisplay();
         break;

      case '+':
         radius += 0.1;
         radius_cyl += 0.1;
         glutPostRedisplay();
         break;

      case '-':
         radius -= 0.1;
         radius_cyl -= 0.1;
         glutPostRedisplay();
         break;

      case 27:
         exit(0);
      }
}

void init(void){
   glClearColor (0.2, 0.8, 0.0, 0.0);  // Setting background color
   glShadeModel (GL_SMOOTH);
}

/**
* This function draws cylinder on the window.
*/
void drawCylinder(){
   gluLookAt(4.0, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);  // Setting the view camera
   GLUquadricObj *quadric;
   quadric = gluNewQuadric();
   if(quadric != 0){
      gluCylinder(quadric, radius_cyl, radius_cyl, radius_cyl*4, 500, 500);  // Drawing the cylinder
   }else{
      printf("Not enough memory to allocate the quadric");
   }
}

/**
* This function draws sphere on the window.
*/
void drawSphere(){
   gluLookAt(4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Setting the view camera
   if(WireFrameOn)
      glutWireSphere(radius, 40, 40);  // Drawing the wire sphere
   else
      glutSolidSphere(radius, 40, 40);  // Drawing the wire sphere
}


void mDisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);  // Setting fill color
   glLoadIdentity();
   if(DRAW_CYLINDER) drawCylinder();
   else drawSphere();
   glFlush();
   glutSwapBuffers();
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
   glutCreateWindow ("Draw dual shape");
   init();
   glutDisplayFunc(mDisplay);
   glutReshapeFunc(mReshape);
   glutKeyboardFunc(mKeyboardFunc);
   glutMainLoop();
   return 0;
}
