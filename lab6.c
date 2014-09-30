#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


float radius = 1.4;
float radius_cyl = 0.5;

int WireFrameOn = 1;

int DRAW_CYLINDER = GL_FALSE;

void mKeyboardFunc( unsigned char key, int x, int y ){
   switch ( key ) {
   case 'w':
      WireFrameOn = 1-WireFrameOn;
      glutPostRedisplay();
      break;
   case 'c':
      DRAW_CYLINDER = GL_TRUE;
      glutPostRedisplay();
      /*
      AngleStepSize *= 1.5;
      if (AngleStepSize>AngleStepMax ) {
         AngleStepSize = AngleStepMax;
      }
      */
      break;
   case 's':
      DRAW_CYLINDER = GL_FALSE;
      glutPostRedisplay();
      break;
   case '+':
      radius += 0.1;
      radius_cyl += 0.1;
      printf("%f", radius);
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
   glClearColor (0.0, 0.0, 0.0, 0.0);  // Setting background color
   glShadeModel (GL_FLAT);
}


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
   glutCreateWindow ("Draw cube");
   init ();
   glutDisplayFunc(mDisplay);
   glutReshapeFunc(mReshape);
   glutKeyboardFunc(mKeyboardFunc);
   glutMainLoop();
   return 0;
}
