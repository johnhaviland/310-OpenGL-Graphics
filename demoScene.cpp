#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include <chrono>
#include <fstream>

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
bool ballShot = false;

float netX = 0.0f;
float netY = 0.8f;
float netWidth = 0.2f;
float netHeight = 0.2f;
bool ballInNet = false;

int score = 0;
int highScore = 0;

const int windowWidth = 1900;
const int windowHeight = 1080;

std::chrono::time_point<std::chrono::steady_clock> startTime;

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

        if (fabs(ballX - basketX) < 0.1f && fabs(ballY - 1.0f) < 0.1f) {
            score++;
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
        }

        if (ballX > 2.0f || ballX < -2.0f || ballY > 2.0f || ballY < -2.0f) {
            ballShot = false;
            ballX = 0.0f;
            ballY = -0.9f;
        }
    }

    if (ballInNet) {
        netY -= 0.01f;
        if (netY < -1.0f) {
            netY = 0.8f;
            ballInNet = false;
        }
    }

    // Implement the time tracking logic
    static bool gameStarted = false;
    if (!gameStarted && ballShot) {
        startTime = std::chrono::steady_clock::now();
        gameStarted = true;
    }

    if (gameStarted) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsedTime >= 60) {
            glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
        }
    }

    if (ballShot) {
        if (ballX >= netX - netWidth / 2 && ballX <= netX + netWidth / 2 &&
            ballY <= netY && ballY >= netY - netHeight) {
            ballInNet = true;
        }
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

void drawNet() {
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the net
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x1 = netX + netWidth / 2 * cosf(theta);
        float y1 = netY - netHeight / 2 * sinf(theta);
        float x2 = netX + netWidth / 2 * cosf(theta + 0.1f);
        float y2 = netY - netHeight / 2 * sinf(theta + 0.1f);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void saveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    } else {
        std::cerr << "Unable to save high score to file!" << std::endl;
    }
}

void loadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        std::cerr << "Unable to load high score from file! Initializing high score to zero." << std::endl;
        highScore = 0;
    }
}

void updateHighScore(int currentScore) {
    if (currentScore > highScore) {
        highScore = currentScore;
        saveHighScore();
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Basketball Flash Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)windowWidth / (GLfloat)windowHeight, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    loadHighScore();

    while (!glfwWindowShouldClose(window)) {
        updateGameLogic();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);

        glPushMatrix();
        glTranslatef(basketX, 1.0f, 0.0f);
        glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
        draw3DCircle(0.2f, 2.0f);
        glPopMatrix();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(basketX - 0.5f, 1.0f);
        glVertex2f(basketX + 0.5f, 1.0f);
        glVertex2f(basketX + 0.5f, 1.1f);
        glVertex2f(basketX - 0.5f, 1.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(basketX - 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.8f);
        glVertex2f(basketX + 0.1f, 0.82f);
        glVertex2f(basketX - 0.1f, 0.82f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.647f, 0.0f);
        glVertex2f(ballX - 0.05f, ballY - 0.05f);
        glVertex2f(ballX + 0.05f, ballY - 0.05f);
        glVertex2f(ballX + 0.05f, ballY + 0.05f);
        glVertex2f(ballX - 0.05f, ballY + 0.05f);
        glEnd();

        // drawNet();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    updateHighScore(score);

    // Display score and high score after the window closes
    std::cout << "Your score: " << score << std::endl;
    std::cout << "High score: " << highScore << std::endl;

    glfwTerminate();
    return 0;
}
