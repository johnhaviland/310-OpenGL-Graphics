#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

// Game variables
float basketX = 0.0f;
float basketSpeed = 0.02f;

float ballX = 0.0f;
float ballY = 0.0f;
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
            ballY = 0.0f;
        }

        // Reset ball if it goes past the screen or reaches the top
        if (ballX > 1.0f || ballX < -1.0f || ballY > 1.0f || ballY < -1.0f) {
            ballShot = false;
            ballX = 0.0f;
            ballY = 0.0f;
        }
    }
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

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window) && score < 5) {
        // Update game logic
        updateGameLogic();

        // Clear the framebuffer
        glClear(GL_COLOR_BUFFER_BIT);

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
        glColor3f(1.0f, 1.0f, 1.0f); // White color for the rim
        glVertex2f(basketX - 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.82f);
        glVertex2f(basketX - 0.1f, 0.82f);
        glEnd();

        // Draw the net (simple representation)
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // White color for the net
        for (float y = 0.8f; y <= 0.9f; y += 0.02f) {
            glVertex2f(basketX - 0.1f, y);
            glVertex2f(basketX + 0.1f, y);
        }
        glEnd();

        // Draw the ball
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ballX - 0.05f, ballY);
        glVertex2f(ballX + 0.05f, ballY);
        glVertex2f(ballX + 0.05f, ballY - 0.1f);
        glVertex2f(ballX - 0.05f, ballY - 0.1f);
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
