#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int x[10]; // Maximum number of vertices can be 10
int y[10];
int num;

float reds[] = {123.0/255, 200.0/255, 0/255, 255.0/255, 150.0/255, 123.0/255, 200.0/255, 0/255, 255.0/255, 150.0/255};
float greens[] = {150.0/255, 255.0/255, 200.0/255, 123.0/255, 180.0/255, 150.0/255, 255.0/255, 200.0/255, 123.0/255, 180.0/255};
float blues[] = {255.0/255, 150.0/255, 0/255, 180.0/255, 150.0/255, 255.0/255, 150.0/255, 0/255, 180.0/255, 150.0/255};

#define WIDTH 1100
#define HEIGHT 700

int BAR_WIDTH = 50;
int BAR_HEIGHT_SCALE_FACTOR = 5;

int no_of_values;
int values[100];


void init(void){
    glClearColor(0, 0, 0, 0);  // Black window
    glClear(GL_COLOR_BUFFER_BIT);  // Clear buffers
    glColor3d(255.0/255, 6.0/255, 0/255);
    glPointSize(10.0);  // Set GL point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void mDisplay(void){
    int i;
    glBegin(GL_LINES);
        glVertex2f(100, 50);
        glVertex2f(1000, 50);
        glVertex2f(100, 50);
        glVertex2f(100, 600);
    glEnd();
    glBegin(GL_LINES);
    glColor3d(0.1, 0.1, 0.1);
    for(i = 100; i <= 550; i += 50){
        glVertex2f(100, i);
        glVertex2f(1000, i);
    }
    glEnd();
        int basex = 200;
        int basey = 50;
        for(i=0; i<no_of_values; i++){
            glBegin(GL_POLYGON);
            float red = reds[i];
            float green = greens[i];
            float blue = blues[i];
            glColor3d(red, green, blue);
            glVertex2i(basex + i*BAR_WIDTH, basey);
            glVertex2i(basex + i*BAR_WIDTH, basey + values[i]*BAR_HEIGHT_SCALE_FACTOR);
            glVertex2i(basex + (i + 1)*BAR_WIDTH, basey + values[i]*BAR_HEIGHT_SCALE_FACTOR);
            glVertex2i(basex + (i + 1)*BAR_WIDTH, basey);
            glEnd();
            glutSwapBuffers();
        }

}

void main(int argc, char *argv[]){
    int i;  // looping variable
    printf("Enter the number of values : ");
    scanf("%d", &no_of_values);

    // Take values from user
    for(i=0; i<no_of_values; i++){
        printf("\nEnter value%d : ", (i+1));
        scanf("%d", &values[i]);
    }

    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Polygon Drawing");
    glutDisplayFunc(mDisplay);  // Register custom display function
    init();
    glutMainLoop();
}
