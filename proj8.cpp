#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265359;
const int num_segments = 100;

float rotationAngleX = 80.0f; // Rotation angle around the x-axis
float rotationAngleY = 0.0f; // Rotation angle around the y-axis

void draw3DCircle(float radius, float lineWidth) {
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        float z = 0.0f;
        glVertex3f(x, y, z);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glColor3f(1.0f, 1.0f, 1.0f);

    glLoadIdentity(); // Load the identity matrix

    // Apply rotations around the x and y axes
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);

    // Adjust the radius and line width as needed
    float radius = 0.5f;
    float lineWidth = 5.0f;

    draw3DCircle(radius, lineWidth);

    glDisable(GL_DEPTH_TEST);
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Rotating 3D Circle");
    init();
    glutDisplayFunc(display);
    //glutTimerFunc(0, timer, 0); // Start the timer
    glutMainLoop();
    return 0;
}


