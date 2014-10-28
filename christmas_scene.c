#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

GLUquadricObj *quadratic;

float t_val = 0.1;
int array_size = 5000;
float snow[5000][2];
int j;


/**
* This function moves snow when 'a' is pressed
*/
void mKeyboardFunc(unsigned char key, int x, int y){
    switch (key) {
        case 'a':
                for(j=0; j < array_size; j++){
                    //snow[j][0] += 0.005;
                    snow[j][1] -= 0.01;
                }
                glutPostRedisplay();
    }
}

/**
* This function initializes the snow array with initial values
*/
void initSnow(){
    int i;
    for(i=0; i < array_size; i++){
        int r1 = rand()%6000;
        int r2 = rand()%1000;
        while(r2 < 50){
            r2 = rand()%1000;
        }
        snow[i][0] = r1*-0.01;
        snow[i][1] = r2*0.01;
    }
}

void resize(int width, int height){
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

/**
* This function draws snow
*/
void drawSnow(){
    // Draw stars
    glColor3d(1, 1, 1);
    srand(time(NULL));

    int i;
    for(i=0; i < array_size; i++){
        glPushMatrix();
            glTranslated(snow[i][0], snow[i][1], -4);
            glRotated(65, -1.0, 0.0, 0.8);
            glutSolidCube(0.02);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-snow[i][0], snow[i][1], -4);
            glRotated(65, -1.0, 0.0, 0.8);
            glutSolidCube(0.02);
        glPopMatrix();
    }
}

/**
* This function draws cubicle gift boxes
*/
void drawGifts(){
    // Four gift boxes
    // Gift box 1(bottom left)
    glColor3d(0.99, 0.39, 0.11);
    glPushMatrix();
        glTranslated(-0.3, 0.55, -5);
        glRotated(65, -1.0, 0.0, 0.8);
        glutSolidCube(0.2);
    glPopMatrix();

    // Gift box 2(top right)
    glColor3d(0.05,0.70,0.33);
    glPushMatrix();
        glTranslated(0.3, 0.95, -5);
        glRotated(65, -1.0, 0.0, 0.5);
        glutSolidCube(0.2);
    glPopMatrix();

    // Gift box 3(top left)
    glColor3d(0.05, 0.06, 0.87);
    glPushMatrix();
        glTranslated(0, 1.6, -5);
        glRotated(65, -1.0, 0.0, 0.5);
        glutSolidCube(0.2);
    glPopMatrix();

    // Gift box 4(bottom right)
    glColor3d(0.99, 0, 0);
    glPushMatrix();
        glTranslated(0.4, 0.25, -5);
        glRotated(65, -1.0, 0.0, 0.8);
        glutSolidCube(0.2);
    glPopMatrix();
}

/**
* This function draws snow man
*/
void drawSnowMan(){
    glColor3d(1, 1, 1);  // Tree color
    glPushMatrix();
        glTranslated(-2.9, 0.35, -7);
        glutSolidSphere(0.55, 200, 200);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2.9, -0.77, -7);
        glutSolidSphere(0.95, 200, 200);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2.9, 1.1, -7);
        glutSolidSphere(0.3, 200, 200);
    glPopMatrix();
    glColor3d(0, 0, 0);  // Tree color
    glPushMatrix();
        glTranslated(-2.70, 1.08, -6.5);
        glutSolidSphere(0.05, 200, 200);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2.90, 1.08, -6.5);
        glutSolidSphere(0.05, 200, 200);
    glPopMatrix();
    glColor3d(1, 0, 0);  // Tree color
    glPushMatrix();
        glTranslated(-2.77, 0.9, -6.5);
        glRotatef(340.0, 1.0, 1.5, 0.0);
        glutSolidCone(0.08, 0.2, 10, 2);
    glPopMatrix();
}

/**
* This function draws the Christmas tree
*/
void drawTree(){
    glColor3d(0.1, 0.5, 0.1);  // Tree color
    // Three cones
    // Cone 1
    glPushMatrix();
        glTranslated(0.0, 1.1, -6);
        glRotated(65, -1.0, 0.0, 0.0);
        glutSolidCone(0.85, 1.6, 100, 100);
    glPopMatrix();

    // Cone 2
    glPushMatrix();
        glTranslated(0.0,0.6,-6);
        glRotated(65, -1.0, 0.0, 0.0);
        glutSolidCone(0.9, 1.5, 100, 100);
    glPopMatrix();

    // Cone 3
    glPushMatrix();
        glTranslated(0.0,0.25,-6);
        glRotated(65, -1.0, 0.0, 0.0);
        glutSolidCone(0.95, 1.5, 100, 100);
    glPopMatrix();

    // Tree base
    glColor3d(0.29, 0.13, 0.13);
    glPushMatrix();
        glTranslated(0.0,-1.15,-6);
        glRotated(65, -1.0, 0.0, 0.0);
        gluCylinder(quadratic, 0.3f, 0.3f, 1.25f, 32, 32);
    glPopMatrix();

    // Tree shadow
    glColor3d(0.9, 0.9, 0.9);
    glPushMatrix();
        glTranslated(0.0,-0.8,-6);
        glRotated(70, -1.0, 0.0, 0.0);
        glutSolidTorus(0.33, 0.60, 200, 200);
    glPopMatrix();
}

/**
* Main GL display function
*/
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSnow();
    drawTree();
    drawSnowMan();
    drawGifts();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(50,40);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST); //enabling z-buffer
    glutCreateWindow("Christmas Tree");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    quadratic = gluNewQuadric();
    glClearColor (0.5, 0.5, 0.5, 0.0);  // Background color
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutKeyboardFunc(mKeyboardFunc);
    initSnow();
    glutMainLoop();
    return 0;
}