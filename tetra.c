#include <GL/glut.h>
#include <stdlib.h>

void resize(int width, int height){
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // Setting fill color
    glPushMatrix();
        glTranslated(-1.0, -1.0, -4.0);
        glutWireTetrahedron();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(400, 30);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Draw tetrahedron");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glClearColor (0.9, 0.3, 0.1, 0.0);  // Setting background color
    glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    glutMainLoop();
    return 0;
}