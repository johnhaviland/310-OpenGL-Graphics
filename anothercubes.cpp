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
  float spacing = 7.0f;
  float scaleFactor = 18.0f;

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
GLfloat cubePosition2 = 0.0f;
GLfloat cubeDirection = 1.0f;
GLfloat cubeDirection2 = -1.0f;

bool isMoving = true; // Global variable to control movement
GLfloat cameraX = 0.0f;
GLfloat cameraY = -5.0f;
GLfloat cameraZ = -20.0f; // Start at -20 on the z-axis to be away from the origin
GLfloat zoom = 1.0f; // Zoom factor

GLfloat rotationAngle = 0.0f; // Rotation angle for the whole scene

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  
  // Set the camera position and zoom
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(cameraX, cameraY, cameraZ * zoom, // Camera position with zoom
            0.0, 0.0, 0.0,                   // Look at the origin
            0.0, 1.0, 0.0);                  // Up vector is in positive Y direction
  // Apply the rotation to the whole scene
  glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f); // Rotate around the y-axis
  
  // Draw the original cube with its original colors
  Cube::draw();
  
  // Save the current transformation matrix
  glPushMatrix();
  // Move up by the cube's size plus a little extra
  glTranslatef(cubePosition, 2.1, 0.0); // Use cubePosition for x-axis
  // Draw the second cube with blended light pink color
  Cube::draw(true);
  // Restore the original transformation matrix
  glPopMatrix();

  // Save the current transformation matrix again
  glPushMatrix();
  // Move up by the cube's size plus a little extra
  glTranslatef(cubePosition2, 4.2, 0.0); // Use cubePosition with cubeDirection2 for x-axis
  // Draw the third cube with blended light pink color
  Cube::draw(true);
  // Restore the original transformation matrix
  glPopMatrix();
  
  drawBlueMeshPlanes();
  
  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 's': // Stop movement when 's' key is pressed
      isMoving = !isMoving; // Toggle the movement state
      break;
    case 'c': // Continue movement when 'c' key is pressed
      isMoving = true;
      break;
    case 'u': // Move up
      if (!isMoving) cameraY += 0.5f;
      break;
    case 'd': // Move down
      if (!isMoving) cameraY -= 0.5f;
      break;
    case '+': // Zoom in
      if (!isMoving) {
        zoom -= 0.1f;
        if (zoom < 0.1f) zoom = 0.1f; // Prevent zooming too far in
      }
      break;
    case '-': // Zoom out
      if (!isMoving) {
        zoom += 0.1f;
        if (zoom > 5.0f) zoom = 5.0f; // Prevent zooming too far out
      }
      break;
    case 'r': // Rotate the whole scene when 'r' key is pressed
      rotationAngle += 5.0f; // Increment the angle by 5 degrees
      if (rotationAngle >= 360.0f) rotationAngle -= 360.0f; // Keep the angle within 0-359 degrees
      break;
  }
  glutPostRedisplay(); // Redraw the scene with new camera settings
}

void timer(int v) {
  if (isMoving) {
    static GLfloat u = 0.0;

    // Define the radii of the ellipse for the x and z axes
    GLfloat radiusX = 2.0; // This will be the radius on the x-axis
    GLfloat radiusZ = 20.0; // This will be the radius on the z-axis

    // Calculate the camera's x and z positions using the parametric equations of an ellipse
    cameraX = radiusX * sin(u);
    cameraZ = radiusZ * cos(u);

    // Update the angle for smooth movement
    u += 0.01;

    // Update cube positions
    cubePosition += cubeDirection * 0.1f; // Adjust speed as necessary
    if (cubePosition > 4.0f || cubePosition < -4.0f) { // Assuming the planes are at x = +/- 5
      cubeDirection *= -1; // Reverse direction when a boundary is hit
    }

    // Update the second cube's position using cubeDirection2
    cubePosition2 += cubeDirection2 * 0.1f; // Adjust speed as necessary
    if (cubePosition2 > 4.0f || cubePosition2 < -4.0f) {
      cubeDirection2 *= -1; // Reverse direction when a boundary is hit
    }
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
  GLfloat aspect = GLfloat(w) / GLfloat(h);
  gluPerspective(60.0 * zoom, aspect, 0.5, 40.0); // Apply zoom to the perspective
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("The RGB Color Cube");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard); // Register the keyboard callback function
  glutTimerFunc(100, timer, 0);
  glutMainLoop();
  return 0;
}
