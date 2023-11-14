#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

const float PI = 3.14159265359;
const int num_segments = 100;

float rotationAngleX = 80.0f; 
float rotationAngleY = 0.0f;

float basketX = 0.0f;
float basketSpeed = 0.02f;

float ballX = 0.0f;
float ballY = -0.9f;
float ballSpeed = 0.05f;
float ballArc = 1.5f;
float ballGravity = -0.001f; 
float ballSize = 0.05f;      
bool ballShot = false;

int score = 0;

const int windowWidth = 1900;
const int windowHeight = 1080;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !ballShot) {
        ballShot = true;
    }
}

void updateGameLogic() {
    basketX += basketSpeed;
    if (basketX >= 2.0f || basketX <= -2.0f) {
        basketSpeed = -basketSpeed;
    }

    if (ballShot) {
        ballX += ballSpeed * cos(ballArc);
        ballY += ballSpeed * sin(ballArc);
        ballSpeed += ballGravity;

        if (fabs(ballX - basketX) < 0.1f && fabs(ballY - 1.0f) < 0.1f) {
            score++;
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
            ballSpeed = 0.05f;
        }

        if (ballX > 2.0f || ballX < -2.0f || ballY > 2.0f || ballY < -2.0f) {
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
            ballSpeed = 0.05f;
        }

        ballSize = std::max(0.01f, 0.05f * (1.0f - (ballY + 0.9f) / 2.0f));
    }
}

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
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Basketball Flash Game", NULL, NULL);
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
        glVertex2f(basketX - 0.5f, 1.0f);
        glVertex2f(basketX + 0.5f, 1.0f);
        glVertex2f(basketX + 0.5f, 1.1f);
        glVertex2f(basketX - 0.5f, 1.1f);
        glEnd();

        // Draw the rim
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for the rim
        glVertex2f(basketX - 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.82f);
        glVertex2f(basketX - 0.1f, 0.82f);
        glEnd();

        // Draw the ball with variable size
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.647f, 0.0f); // Orange color for the ball
        glVertex2f(ballX - ballSize, ballY - ballSize);
        glVertex2f(ballX + ballSize, ballY - ballSize);
        glVertex2f(ballX + ballSize, ballY + ballSize);
        glVertex2f(ballX - ballSize, ballY + ballSize);
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
