#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a white rectangle
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);  // White color
    glVertex2f(100, 100);     // Bottom-left vertex
    glVertex2f(400, 100);     // Bottom-right vertex
    glVertex2f(400, 400);     // Top-right vertex
    glVertex2f(100, 400);     // Top-left vertex
    glEnd();

    // Draw a white square
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);  // White color
    glVertex2f(450, 100);     // Bottom-left vertex
    glVertex2f(650, 100);     // Bottom-right vertex
    glVertex2f(650, 300);     // Top-right vertex
    glVertex2f(450, 300);     // Top-left vertex
    glEnd();

    // Draw a white parallelogram
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);  // White color
    glVertex2f(100, 500);     // Bottom-left vertex
    glVertex2f(350, 500);     // Bottom-right vertex
    glVertex2f(250, 700);     // Top-right vertex
    glVertex2f(0, 700);       // Top-left vertex
    glEnd();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(703, 980);
    glutCreateWindow("Quadrilaterals");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
