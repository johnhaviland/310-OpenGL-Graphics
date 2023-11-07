#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

namespace Cube {
const int NUM_VERTICES = 8;
const int NUM_FACES = 6;

GLfloat vertices[NUM_VERTICES][3] = {
  {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5}, {-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5},
  {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, -0.5}, {0.5, 0.5, 0.5}
};

GLint faces[NUM_FACES][4] = {
  {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
  {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}
};

GLfloat vertexColors[NUM_VERTICES][3] = {
  {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
  {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}
};

void draw() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glBegin(GL_QUADS);
  for (int i = 0; i < NUM_FACES; i++) {
    for (int j = 0; j < 4; j++) {
      glColor3fv(vertexColors[faces[i][j]]);
      glVertex3fv(vertices[faces[i][j]]);
    }
  }
  glEnd();
  glDisable(GL_CULL_FACE);
}
}

void drawBlueMeshPlanes() {
  float spacing = 5.0f;
  float scaleFactor = 12.0f;

  // Draw the left blue mesh plane
  glColor3f(0.0, 0.0, 1.0); // Blue color
  glBegin(GL_QUADS);
  glVertex3f(-spacing, -0.5*scaleFactor, -0.5*scaleFactor);
  glVertex3f(-spacing, -0.5*scaleFactor, 0.5*scaleFactor);
  glVertex3f(-spacing, 0.5*scaleFactor, 0.5*scaleFactor);
  glVertex3f(-spacing, 0.5*scaleFactor, -0.5*scaleFactor);
  glEnd();

  // Draw the right blue mesh plane
  glBegin(GL_QUADS);
  glVertex3f(spacing, -0.5*scaleFactor, -0.5*scaleFactor);
  glVertex3f(spacing, -0.5*scaleFactor, 0.5*scaleFactor);
  glVertex3f(spacing, 0.5*scaleFactor, 0.5*scaleFactor);
  glVertex3f(spacing, 0.5*scaleFactor, -0.5*scaleFactor);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  Cube::draw();
  drawBlueMeshPlanes();
  glFlush();
  glutSwapBuffers();
}

void timer(int v) {
  static GLfloat u = 0.0;

  // Define the radii of the ellipse for the x and z axes
  GLfloat radiusX = 2.0; // This will be the radius on the x-axis
  GLfloat radiusZ = 25.0; // This will be the radius on the z-axis

  // Calculate the camera's x and z positions using the parametric equations of an ellipse
  GLfloat cameraX = radiusX * sin(u);
  GLfloat cameraZ = radiusZ * cos(u);

  // Update the angle for smooth movement
  u += 0.01;

  // Set the camera position and orientation
  glLoadIdentity();
  // Camera is placed on an elliptical path around the cube, looking at the center of the cube
  // The up vector is set to always point in the positive y-direction
  gluLookAt(cameraX, -4, cameraZ,  // Camera position on the elliptical path
            0, 0, 0,               // Look at the center of the cube
            0, 1, 0);              // Up vector

  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, v);
}



void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("The RGB Color Cube");
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
