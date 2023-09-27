#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the outline color to white
    glColor3f(1.0, 1.0, 1.0);  // White color

    // #1
    glBegin(GL_LINE_LOOP);
    glVertex2f(100, 100);     // Bottom-left vertex
    glVertex2f(400, 100);     // Bottom-right vertex
    glVertex2f(400, 400);     // Top-right vertex
    glVertex2f(100, 400);     // Top-left vertex
    glEnd();
/*
    // #2
    glBegin(GL_LINE_LOOP);
    glVertex2f(150, 150);     // Bottom-left vertex
    glVertex2f(350, 150);     // Bottom-right vertex
    glVertex2f(350, 350);     // Top-right vertex
    glVertex2f(150, 350);     // Top-left vertex
    glEnd();

    // #3
    glBegin(GL_LINE_LOOP);
    glVertex2f(200, 200);     // Bottom-left vertex
    glVertex2f(300, 200);     // Bottom-right vertex
    glVertex2f(300, 300);     // Top-right vertex
    glVertex2f(200, 300);     // Top-left vertex
    glEnd();

    // #4
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 250);     // Bottom-left vertex
    glVertex2f(270, 250);     // Bottom-right vertex
    glVertex2f(270, 270);     // Top-right vertex
    glVertex2f(250, 270);     // Top-left vertex
    glEnd();

    // #5
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 300);     // Bottom-left vertex
    glVertex2f(300, 300);     // Bottom-right vertex
    glVertex2f(300, 350);     // Top-right vertex
    glVertex2f(250, 350);     // Top-left vertex
    glEnd();

    // #6
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 350);     // Bottom-left vertex
    glVertex2f(300, 350);     // Bottom-right vertex
    glVertex2f(300, 400);     // Top-right vertex
    glVertex2f(250, 400);     // Top-left vertex
    glEnd();

    // #7
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 400);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(400, 450);     // Top-right vertex
    glVertex2f(250, 450);     // Top-left vertex
    glEnd();

    // #8
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 450);     // Bottom-left vertex
    glVertex2f(350, 450);     // Bottom-right vertex
    glVertex2f(350, 500);     // Top-right vertex
    glVertex2f(250, 500);     // Top-left vertex
    glEnd();

    // #9
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(300, 500);     // Bottom-right vertex
    glVertex2f(300, 550);     // Top-right vertex
    glVertex2f(250, 550);     // Top-left vertex
    glEnd();

    // #10
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 550);     // Bottom-left vertex
    glVertex2f(275, 550);     // Bottom-right vertex
    glVertex2f(275, 600);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #11
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 400);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(350, 450);     // Top-right vertex
    glVertex2f(250, 450);     // Top-left vertex
    glEnd();

    // #12
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 450);     // Bottom-left vertex
    glVertex2f(350, 450);     // Bottom-right vertex
    glVertex2f(350, 500);     // Top-right vertex
    glVertex2f(250, 500);     // Top-left vertex
    glEnd();

    // #13
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(400, 450);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #14
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 400);     // Bottom-left vertex
    glVertex2f(350, 450);     // Bottom-right vertex
    glVertex2f(400, 400);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #15
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(350, 450);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #16
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 400);     // Bottom-left vertex
    glVertex2f(350, 450);     // Bottom-right vertex
    glVertex2f(350, 500);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #17
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(275, 550);     // Bottom-right vertex
    glVertex2f(275, 600);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #18
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(400, 450);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #19
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 400);     // Bottom-left vertex
    glVertex2f(350, 450);     // Bottom-right vertex
    glVertex2f(400, 400);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #20
    glBegin(GL_LINE_LOOP);
    glVertex2f(250, 500);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(350, 450);     // Top-right vertex
    glVertex2f(250, 600);     // Top-left vertex
    glEnd();

    // #21
    glBegin(GL_LINE_LOOP);
    glVertex2f(350, 450);     // Bottom-left vertex
    glVertex2f(400, 400);     // Bottom-right vertex
    glVertex2f(400, 450);     // Top-right vertex
    glVertex2f(350, 500);     // Top-left vertex
    glEnd();

    // #22
    glBegin(GL_LINE_LOOP);
    glVertex2f(400, 400);     // Bottom-left vertex
    glVertex2f(450, 400);     // Bottom-right vertex
    glVertex2f(450, 450);     // Top-right vertex
    glVertex2f(400, 450);     // Top-left vertex
    glEnd();

    // #23
    glBegin(GL_LINE_LOOP);
    glVertex2f(400, 400);     // Bottom-left vertex
    glVertex2f(450, 400);     // Bottom-right vertex
    glVertex2f(450, 450);     // Top-right vertex
    glVertex2f(400, 450);     // Top-left vertex
    glEnd();

    // #24
    glBegin(GL_LINE_LOOP);
    glVertex2f(450, 400);     // Bottom-left vertex
    glVertex2f(500, 400);     // Bottom-right vertex
    glVertex2f(500, 450);     // Top-right vertex
    glVertex2f(450, 450);     // Top-left vertex
    glEnd();

    // #25
    glBegin(GL_LINE_LOOP);
    glVertex2f(400, 400);     // Bottom-left vertex
    glVertex2f(500, 400);     // Bottom-right vertex
    glVertex2f(450, 450);     // Top-right vertex
    glVertex2f(400, 450);     // Top-left vertex
    glEnd();

    // #26
    glBegin(GL_LINE_LOOP);
    glVertex2f(500, 400);     // Bottom-left vertex
    glVertex2f(550, 400);     // Bottom-right vertex
    glVertex2f(550, 450);     // Top-right vertex
    glVertex2f(500, 450);     // Top-left vertex
    glEnd();

    // #27
    glBegin(GL_LINE_LOOP);
    glVertex2f(550, 400);     // Bottom-left vertex
    glVertex2f(600, 400);     // Bottom-right vertex
    glVertex2f(600, 450);     // Top-right vertex
    glVertex2f(550, 450);     // Top-left vertex
    glEnd();

    // #28
    glBegin(GL_LINE_LOOP);
    glVertex2f(600, 400);     // Bottom-left vertex
    glVertex2f(650, 400);     // Bottom-right vertex
    glVertex2f(650, 450);     // Top-right vertex
    glVertex2f(600, 450);     // Top-left vertex
    glEnd();

    // #29
    glBegin(GL_LINE_LOOP);
    glVertex2f(650, 400);     // Bottom-left vertex
    glVertex2f(700, 400);     // Bottom-right vertex
    glVertex2f(700, 450);     // Top-right vertex
    glVertex2f(650, 450);     // Top-left vertex
    glEnd();

    // #30
    glBegin(GL_LINE_LOOP);
    glVertex2f(500, 450);     // Bottom-left vertex
    glVertex2f(550, 450);     // Bottom-right vertex
    glVertex2f(550, 500);     // Top-right vertex
    glVertex2f(500, 500);     // Top-left vertex
    glEnd();

    // #31
    glBegin(GL_LINE_LOOP);
    glVertex2f(550, 450);     // Bottom-left vertex
    glVertex2f(600, 450);     // Bottom-right vertex
    glVertex2f(600, 500);     // Top-right vertex
    glVertex2f(550, 500);     // Top-left vertex
    glEnd();

    // #32
    glBegin(GL_LINE_LOOP);
    glVertex2f(600, 450);     // Bottom-left vertex
    glVertex2f(650, 450);     // Bottom-right vertex
    glVertex2f(650, 500);     // Top-right vertex
    glVertex2f(600, 500);     // Top-left vertex
    glEnd();

    // #33
    glBegin(GL_LINE_LOOP);
    glVertex2f(550, 500);     // Bottom-left vertex
    glVertex2f(575, 500);     // Bottom-right vertex
    glVertex2f(575, 550);     // Top-right vertex
    glVertex2f(550, 550);     // Top-left vertex
    glEnd();

    // #34
    glBegin(GL_LINE_LOOP);
    glVertex2f(600, 450);     // Bottom-left vertex
    glVertex2f(650, 450);     // Bottom-right vertex
    glVertex2f(650, 500);     // Top-right vertex
    glVertex2f(600, 500);     // Top-left vertex
    glEnd();

    // #35
    glBegin(GL_LINE_LOOP);
    glVertex2f(650, 450);     // Bottom-left vertex
    glVertex2f(700, 450);     // Bottom-right vertex
    glVertex2f(700, 500);     // Top-right vertex
    glVertex2f(650, 500);     // Top-left vertex
    glEnd();

    // #36
    glBegin(GL_LINE_LOOP);
    glVertex2f(550, 500);     // Bottom-left vertex
    glVertex2f(575, 550);     // Bottom-right vertex
    glVertex2f(600, 500);     // Top-right vertex
    glVertex2f(550, 550);     // Top-left vertex
    glEnd();

    // #37
    glBegin(GL_LINE_LOOP);
    glVertex2f(600, 500);     // Bottom-left vertex
    glVertex2f(575, 550);     // Bottom-right vertex
    glVertex2f(650, 500);     // Top-right vertex
    glVertex2f(600, 550);     // Top-left vertex
    glEnd();

    // #38
    glBegin(GL_LINE_LOOP);
    glVertex2f(650, 500);     // Bottom-left vertex
    glVertex2f(700, 500);     // Bottom-right vertex
    glVertex2f(675, 550);     // Top-right vertex
    glVertex2f(650, 550);     // Top-left vertex
    glEnd();

    // #39
    glBegin(GL_LINE_LOOP);
    glVertex2f(575, 550);     // Bottom-left vertex
    glVertex2f(600, 550);     // Bottom-right vertex
    glVertex2f(575, 600);     // Top-right vertex
    glVertex2f(550, 600);     // Top-left vertex
    glEnd();

    // #40
    glBegin(GL_LINE_LOOP);
    glVertex2f(600, 550);     // Bottom-left vertex
    glVertex2f(650, 550);     // Bottom-right vertex
    glVertex2f(625, 600);     // Top-right vertex
    glVertex2f(600, 600);     // Top-left vertex
    glEnd();

    // #41
    glBegin(GL_LINE_LOOP);
    glVertex2f(650, 550);     // Bottom-left vertex
    glVertex2f(700, 550);     // Bottom-right vertex
    glVertex2f(675, 600);     // Top-right vertex
    glVertex2f(650, 600);     // Top-left vertex
    glEnd();

    // #42
    glBegin(GL_LINE_LOOP);
    glVertex2f(575, 600);     // Bottom-left vertex
    glVertex2f(625, 600);     // Bottom-right vertex
    glVertex2f(600, 650);     // Top-right vertex
    glVertex2f(575, 650);     // Top-left vertex
    glEnd();

    // #43
    glBegin(GL_LINE_LOOP);
    glVertex2f(625, 600);     // Bottom-left vertex
    glVertex2f(675, 600);     // Bottom-right vertex
    glVertex2f(650, 650);     // Top-right vertex
    glVertex2f(625, 650);     // Top-left vertex
    glEnd();

    // #44
    glBegin(GL_LINE_LOOP);
    glVertex2f(575, 650);     // Bottom-left vertex
    glVertex2f(625, 650);     // Bottom-right vertex
    glVertex2f(600, 700);     // Top-right vertex
    glVertex2f(575, 700);     // Top-left vertex
    glEnd();

    // #45
    glBegin(GL_LINE_LOOP);
    glVertex2f(625, 650);     // Bottom-left vertex
    glVertex2f(675, 650);     // Bottom-right vertex
    glVertex2f(650, 700);     // Top-right vertex
    glVertex2f(625, 700);     // Top-left vertex
    glEnd();

    // #46
    glBegin(GL_LINE_LOOP);
    glVertex2f(575, 700);     // Bottom-left vertex
    glVertex2f(625, 700);     // Bottom-right vertex
    glVertex2f(600, 750);     // Top-right vertex
    glVertex2f(575, 750);     // Top-left vertex
    glEnd();
*/
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
