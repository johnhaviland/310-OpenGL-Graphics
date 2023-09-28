#include <GL/glut.h>

void display() {
    // Set the clear color to sky blue (sky background)
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate the scene to the center
    glTranslatef(485 / 2, 662 / 2, 0.0f);

    // Apply a 180-degree rotation around the Z-axis
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

    // Translate back to the original position
    glTranslatef(-485 / 2, -662 / 2, 0.0f);

    // Set the outline color to black
    glColor3f(0.0, 0.0, 0.0);

    // #1
    glBegin(GL_LINE_LOOP);
    glVertex2f(307, 569);     // Bottom-left vertex
    glVertex2f(428, 538);     // Bottom-right vertex
    glVertex2f(433, 217);     // Top-right vertex
    glVertex2f(317, 195);     // Top-left vertex
    glEnd();

    // #2
    glBegin(GL_LINE_LOOP);
    glVertex2f(329, 446);     // Bottom-left vertex
    glVertex2f(421, 450);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(331, 321);     // Top-left vertex
    glEnd();

    // #3
    glBegin(GL_LINE_LOOP);
    glVertex2f(412, 451);     // Bottom-left vertex
    glVertex2f(421, 450);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(412, 333);     // Top-left vertex
    glEnd();

    // #4
    glBegin(GL_LINE_LOOP);
    glVertex2f(332, 326);     // Bottom-left vertex
    glVertex2f(412, 333);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(331, 321);     // Top-left vertex
    glEnd();

    // #5
    glBegin(GL_LINE_LOOP);
    glVertex2f(304, 628);     // Bottom-left vertex
    glVertex2f(427, 595);     // Bottom-right vertex
    glVertex2f(428, 538);     // Top-right vertex
    glVertex2f(306, 569);     // Top-left vertex
    glEnd();

    // #6
    glBegin(GL_LINE_LOOP);
    glVertex2f(304, 642);     // Bottom-left vertex
    glVertex2f(427, 611);     // Bottom-right vertex
    glVertex2f(427, 595);     // Top-right vertex
    glVertex2f(304, 628);     // Top-left vertex
    glEnd();

    // #7
    glBegin(GL_LINE_LOOP);
    glVertex2f(427, 611);     // Bottom-left vertex
    glVertex2f(485, 643);     // Bottom-right vertex
    glVertex2f(485, 73);     // Top-right vertex
    glVertex2f(431, 94);     // Top-left vertex
    glEnd();

    // #8
    glBegin(GL_LINE_LOOP);
    glVertex2f(317, 195);     // Bottom-left vertex
    glVertex2f(433, 217);     // Bottom-right vertex
    glVertex2f(431, 94);     // Top-right vertex
    glVertex2f(322, 67);     // Top-left vertex
    glEnd();

    // #9
    glBegin(GL_LINE_LOOP);
    glVertex2f(335, 189);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();

    // #10
    glBegin(GL_LINE_LOOP);
    glVertex2f(409, 203);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(410, 110);     // Top-left vertex
    glEnd();

    // #11
    glBegin(GL_LINE_LOOP);
    glVertex2f(336, 95);     // Bottom-left vertex
    glVertex2f(410, 110);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();

    // #12
    glBegin(GL_LINE_LOOP);
    glVertex2f(256, 546);     // Bottom-left vertex
    glVertex2f(307, 569);     // Bottom-right vertex
    glVertex2f(317, 195);     // Top-right vertex
    glVertex2f(272, 221);     // Top-left vertex
    glEnd();

    // #13
    glBegin(GL_LINE_LOOP);
    glVertex2f(272, 221);     // Bottom-left vertex
    glVertex2f(317, 195);     // Bottom-right vertex
    glVertex2f(321, 69);     // Top-right vertex
    glVertex2f(275, 104);     // Top-left vertex
    glEnd();

    // #14
    glBegin(GL_LINE_LOOP);
    glVertex2f(184, 194);     // Bottom-left vertex
    glVertex2f(276, 125);     // Bottom-right vertex
    glVertex2f(275, 104);     // Top-right vertex
    glVertex2f(183, 178);     // Top-left vertex
    glEnd();

    // #15
    glBegin(GL_LINE_LOOP);
    glVertex2f(262, 606);     // Bottom-left vertex
    glVertex2f(304, 628);     // Bottom-right vertex
    glVertex2f(306, 569);     // Top-right vertex
    glVertex2f(264, 550);     // Top-left vertex
    glEnd();

    // #16
    glBegin(GL_LINE_LOOP);
    glVertex2f(260, 620);     // Bottom-left vertex
    glVertex2f(304, 642);     // Bottom-right vertex
    glVertex2f(304, 628);     // Top-right vertex
    glVertex2f(262, 606);     // Top-left vertex
    glEnd();

    // #17
    glBegin(GL_LINE_LOOP);
    glVertex2f(175, 623);     // Bottom-left vertex
    glVertex2f(262, 606);     // Bottom-right vertex
    glVertex2f(265, 539);     // Top-right vertex
    glVertex2f(180, 553);     // Top-left vertex
    glEnd();

    // #18
    glBegin(GL_LINE_LOOP);
    glVertex2f(175, 637);     // Bottom-left vertex
    glVertex2f(260, 620);     // Bottom-right vertex
    glVertex2f(262, 606);     // Top-right vertex
    glVertex2f(175, 624);     // Top-left vertex
    glEnd();
    

    // #19
    glBegin(GL_LINE_LOOP);
    glVertex2f(54, 615);     // Bottom-left vertex
    glVertex2f(175, 624);     // Bottom-right vertex
    glVertex2f(180, 553);     // Top-right vertex
    glVertex2f(62, 545);     // Top-left vertex
    glEnd();
    

    // #20
    glBegin(GL_LINE_LOOP);
    glVertex2f(52, 628);     // Bottom-left vertex
    glVertex2f(175, 637);     // Bottom-right vertex
    glVertex2f(175, 624);     // Top-right vertex
    glVertex2f(54, 615);     // Top-left vertex
    glEnd();


    // #21
    glBegin(GL_LINE_LOOP);
    glVertex2f(42, 593);     // Bottom-left vertex
    glVertex2f(54, 615);     // Bottom-right vertex
    glVertex2f(62, 545);     // Top-right vertex
    glVertex2f(43, 528);     // Top-left vertex
    glEnd();


    // #22
    glBegin(GL_LINE_LOOP);
    glVertex2f(42, 601);     // Bottom-left vertex
    glVertex2f(52, 628);     // Bottom-right vertex
    glVertex2f(54, 615);     // Top-right vertex
    glVertex2f(42, 593);     // Top-left vertex
    glEnd();


    // #23
    glBegin(GL_LINE_LOOP);
    glVertex2f(179, 553);     // Bottom-left vertex
    glVertex2f(265, 539);     // Bottom-right vertex
    glVertex2f(266, 475);     // Top-right vertex
    glVertex2f(186, 486);     // Top-left vertex
    glEnd();

    // #24
    glBegin(GL_LINE_LOOP);
    glVertex2f(62, 545);     // Bottom-left vertex
    glVertex2f(180, 553);     // Bottom-right vertex
    glVertex2f(186, 486);     // Top-right vertex
    glVertex2f(65, 481);     // Top-left vertex
    glEnd();

    // #25
    glBegin(GL_LINE_LOOP);
    glVertex2f(43, 528);     // Bottom-left vertex
    glVertex2f(62, 545);     // Bottom-right vertex
    glVertex2f(65, 481);     // Top-right vertex
    glVertex2f(43, 465);     // Top-left vertex
    glEnd();

    // #26
    glBegin(GL_LINE_LOOP);
    glVertex2f(189, 487);     // Bottom-left vertex
    glVertex2f(272, 475);     // Bottom-right vertex
    glVertex2f(272, 458);     // Top-right vertex
    glVertex2f(189, 469);     // Top-left vertex
    glEnd();

    // #27
    glBegin(GL_LINE_LOOP);
    glVertex2f(65, 481);     // Bottom-left vertex
    glVertex2f(189, 487);     // Bottom-right vertex
    glVertex2f(189, 469);     // Top-right vertex
    glVertex2f(65, 464);     // Top-left vertex
    glEnd();

    // #28
    glBegin(GL_LINE_LOOP);
    glVertex2f(43, 465);     // Bottom-left vertex
    glVertex2f(65, 481);     // Bottom-right vertex
    glVertex2f(65, 464);     // Top-right vertex
    glVertex2f(45, 453);     // Top-left vertex
    glEnd();

    // #29
    glBegin(GL_LINE_LOOP);
    glVertex2f(98, 464);     // Bottom-left vertex
    glVertex2f(177, 467);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(170, 362);     // Top-left vertex
    glEnd();

    // #30
    glBegin(GL_LINE_LOOP);
    glVertex2f(241, 463);     // Bottom-left vertex
    glVertex2f(263, 459);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(247, 364);     // Top-left vertex
    glEnd();
/*
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
    glutInitWindowSize(485, 662);
    glutCreateWindow("Project 4 Rendering");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
