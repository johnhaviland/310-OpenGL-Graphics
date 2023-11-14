#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

// Constants and variables from the second code
const float PI = 3.14159265359;
const int num_segments = 100;

float rotationAngleX = 80.0f; // Rotation angle around the x-axis
float rotationAngleY = 0.0f; // Rotation angle around the y-axis

// Game variables
float basketX = 0.0f;
float basketSpeed = 0.02f;

float ballX = 0.0f;
float ballY = -0.9f;
float ballSpeed = 0.05f;  // Adjusted for slower speed
float ballArc = 1.0f;    // Adjusted to arch towards the side of the rim
bool ballShot = false;

int score = 0;

// Window size
const int windowWidth = 1900;
const int windowHeight = 1080;


// Function to handle key presses
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !ballShot) {
        ballShot = true;
    }
}

// Function to update the game logic
void updateGameLogic() {
    // Update basket position
    basketX += basketSpeed;
    if (basketX >= 1.0f || basketX <= -1.0f) {
        basketSpeed = -basketSpeed;
    }

    // Update ball position and trajectory when shot
    if (ballShot) {
        ballX += ballSpeed * cos(ballArc);
        ballY += ballSpeed * sin(ballArc);

        // Check if the ball is in the basket
        if (fabs(ballX - basketX) < 0.2f && fabs(ballY) < 0.02f) {
            score++;
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
        }

        // Reset ball if it goes past the screen or reaches the top
        if (ballX > 1.0f || ballX < -1.0f || ballY > 1.0f || ballY < -1.0f) {
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
        }
    }
}

// Function to draw a 3D circle for the hoop
void draw3DCircle(float radius, float lineWidth) {
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        float z = 0.28f;
        glVertex3f(x, y, z);
    }
    glEnd();
}


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Basketball Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the key callback function
    glfwSetKeyCallback(window, key_callback);

    // Set up viewport and projection
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)windowWidth / (GLfloat)windowHeight, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window) && score < 5) {
        // Update game logic
        updateGameLogic();

        // Render scene
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);

        // Draw the hoop
        glPushMatrix();
        glTranslatef(basketX, 1.0f, 0.0f); // Adjust to place the hoop correctly
        glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
        draw3DCircle(0.2f, 2.0f);
        glPopMatrix();

        // Draw the backboard
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue color for the backboard
        glVertex2f(basketX - 0.3f, 0.8f);
        glVertex2f(basketX + 0.3f, 0.8f);
        glVertex2f(basketX + 0.3f, 0.9f);
        glVertex2f(basketX - 0.3f, 0.9f);
        glEnd();

        // Draw the rim
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for the rim
        glVertex2f(basketX - 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.82f);
        glVertex2f(basketX - 0.1f, 0.82f);
        glEnd();

        // Draw the ball
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.647f, 0.0f); // Orange color for the ball
        glVertex2f(ballX - 0.05f, ballY - 0.05f);
        glVertex2f(ballX + 0.05f, ballY - 0.05f);
        glVertex2f(ballX + 0.05f, ballY + 0.05f);
        glVertex2f(ballX - 0.05f, ballY + 0.05f);
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
