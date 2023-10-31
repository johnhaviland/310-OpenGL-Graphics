#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>
#include <cmath>

// Define a 2 x 2 red and yellow checkered pattern using RGB colors.
#define red {0xff, 0x00, 0x00}
#define yellow {0xff, 0xff, 0x00}
#define magenta {0xff, 0, 0xff}
GLubyte texture[][3] = {
    red, yellow,
    yellow, red,
};

// rotation & translation variables
GLfloat angle = 0.0;
GLfloat translationX = 0.0;
GLfloat translationY = 0.0;
GLfloat zoom = 1.0;

// spinning state
bool spinning = true;

// Keyboard input handling
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'p': // Stop spinning
            spinning = false;
            break;
        case 'c': // Start spinning
            spinning = true;
            break;
        case 'u': // Move up
            translationY += 0.25;
            break;
        case 'd': // Move down
            translationY -= 0.25;
            break;
        case 'L': // Move left
            translationX -= 0.25;
            break;
        case 'R': // Move right
            translationX += 0.25;
            break;
        case '+': // Zoom in
            zoom += 0.25;
            break;
        case '-': // Zoom out
            zoom -= 0.25;
            break;
    }
    glutPostRedisplay();
}

// Function that fixes camera and remaps texture when window reshapes
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, GLfloat(width)/height, 1, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2, -1, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // level 0, use only RGB components, texture has 2x2 texels, no border, texels are in RGB format, color components are unsigned bytes
    glTexImage2D(GL_TEXTURE_2D, 0, 3, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

// Draws three textured triangles.  Each triangle uses the same texture,
// but the mappings of texture coordinates to vertex coordinates is
// different in each triangle.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply transformations
    glTranslatef(translationX, translationY, -5.0);
    glScalef(zoom, zoom, 1.0);

    if (spinning) {
        angle += 1.0;
        if (angle >= 360.0)
            angle = 0.0;
    }
    glRotatef(angle, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.5, 1.0);    glVertex2f(-3, 3);
        glTexCoord2f(0.0, 0.0);    glVertex2f(-3, 0);
        glTexCoord2f(1.0, 0.0);    glVertex2f(0, 0);

        glTexCoord2f(4, 8);        glVertex2f(3, 3);
        glTexCoord2f(0.0, 0.0);    glVertex2f(0, 0);
        glTexCoord2f(8, 0.0);      glVertex2f(3, 0);

        glTexCoord2f(5, 5);        glVertex2f(0, 0);
        glTexCoord2f(0.0, 0.0);    glVertex2f(-1.5, -3);
        glTexCoord2f(4, 0.0);      glVertex2f(1.5, -3);
    glEnd();
    glFlush();
}

// Enters main loop, initialize glut
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(520, 390);
    glutCreateWindow("MODIFIED Textured Triangles");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

