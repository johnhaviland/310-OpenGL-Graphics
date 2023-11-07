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

GLfloat lightPink[3] = {1.0f, 0.75f, 0.8f}; // RGB for light pink

void draw(bool useLightPink = false) {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glBegin(GL_QUADS);
  for (int i = 0; i < NUM_FACES; i++) {
    for (int j = 0; j < 4; j++) {
      if (useLightPink) {
        // Blend the light pink color with the original vertex color
        GLfloat blendedColor[3] = {
          (lightPink[0] + vertexColors[faces[i][j]][0]) / 2,
          (lightPink[1] + vertexColors[faces[i][j]][1]) / 2,
          (lightPink[2] + vertexColors[faces[i][j]][2]) / 2
        };
        glColor3fv(blendedColor);
      } else {
        glColor3fv(vertexColors[faces[i][j]]);
      }
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

// Global variables for cube movement
GLfloat cubePosition = 0.0f;
GLfloat cubeDirection = 1.0f;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  
  // Draw the original cube with its original colors
  Cube::draw();
  
  // Save the current transformation matrix
  glPushMatrix();
  // Move up by the cube's size plus a little extra
  glTranslatef(cubePosition, 3.1, 0.0); // Use cubePosition for x-axis
  // Draw the second cube with blended light pink color
  Cube::draw(true);
  // Move up by the cube's size plus a little extra again
  glTranslatef(0.0, 3.1, 0.0);
  // Draw the third cube with blended light pink color
  Cube::draw(true);
  // Restore the original transformation matrix
  glPopMatrix();
  
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
  gluLookAt(cameraX, -4, cameraZ,  // Camera position on the elliptical path
            0, 0, 0,               // Look at the center of the cube
            0, 1, 0);              // Up vector

  // Update cube position
  cubePosition += cubeDirection * 0.1f; // Adjust speed as necessary
  if (cubePosition > 4.0f || cubePosition < -4.0f) { // Assuming the planes are at x = +/- 5
    cubeDirection *= -1; // Reverse direction when a boundary is hit
  }

  // Redraw the scene by calling glutPostRedisplay
  glutPostRedisplay();

  // Register the timer callback function again
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
