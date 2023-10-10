#include <GL/glew.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <fstream>
#include <string>

GLuint textureID; // Texture ID
GLuint shaderProgram;

const char* vertexShaderSource = R"(
    void main() {
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    }
)";

const char* fragmentShaderSource = R"(
    	uniform sampler2D texture;
	uniform float opacity;

	void main() {
	    vec4 texColor = texture2D(texture, gl_TexCoord[0].st);
	    gl_FragColor = mix(gl_Color, texColor, opacity); // Preserve original color
}
)";
void loadTexture() {
    int width, height;
    unsigned char* image = SOIL_load_image("drywall.png", &width, &height, 0, SOIL_LOAD_RGBA);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
}

void setupShaders() {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Load vertex shader from file
    std::ifstream vertexShaderFile("vertexShader.glsl");
    std::string vertexShaderSource((std::istreambuf_iterator<char>(vertexShaderFile)),
                                std::istreambuf_iterator<char>());
    const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL);
    glCompileShader(vertexShader);

    // Load fragment shader from file
    std::ifstream fragmentShaderFile("fragmentShader.glsl");
    std::string fragmentShaderSource((std::istreambuf_iterator<char>(fragmentShaderFile)),
                                  std::istreambuf_iterator<char>());
    const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void display() {
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(485 / 2, 662 / 2, 0.0f);
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-485 / 2, -662 / 2, 0.0f);

    // Set the outline color to sky blue (TEST)
    glColor3f(0.529f, 0.808f, 0.922f);

    // Set the outline color to black
    glColor3f(0.0, 0.0, 0.0);
  

    // #1
    glBegin(GL_POLYGON);  // Use GL_POLYGON for filled shapes
    glColor3f(0.7, 0.7, 0.7); // Light gray color
    glVertex2f(307, 569);
    glVertex2f(428, 538);
    glVertex2f(433, 217);
    glVertex2f(317, 195);
    glEnd();

    // #2
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(329, 446);     // Bottom-left vertex
    glVertex2f(421, 450);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(331, 321);     // Top-left vertex
    glEnd();

    // #3
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(412, 451);     // Bottom-left vertex
    glVertex2f(421, 450);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(412, 333);     // Top-left vertex
    glEnd();

    // #4
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(332, 326);     // Bottom-left vertex
    glVertex2f(412, 333);     // Bottom-right vertex
    glVertex2f(421, 329);     // Top-right vertex
    glVertex2f(331, 321);     // Top-left vertex
    glEnd();

    // #5
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(304, 628);
    glVertex2f(427, 595);
    glVertex2f(428, 538);
    glVertex2f(306, 569);
    glEnd();

    // #6
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(304, 642);     // Bottom-left vertex
    glVertex2f(427, 611);     // Bottom-right vertex
    glVertex2f(427, 595);     // Top-right vertex
    glVertex2f(304, 628);     // Top-left vertex
    glEnd();

    // #7
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(427, 611);     // Bottom-left vertex
    glVertex2f(485, 643);     // Bottom-right vertex
    glVertex2f(485, 73);     // Top-right vertex
    glVertex2f(431, 94);     // Top-left vertex
    glEnd();

    // #8
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(317, 195);
    glVertex2f(433, 217);
    glVertex2f(431, 94);
    glVertex2f(322, 67);
    glEnd();

    // #9
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.8,0.7);
    glVertex2f(335, 189);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();

    // #10
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(409, 203);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(410, 110);     // Top-left vertex
    glEnd();

    // #11
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(336, 95);     // Bottom-left vertex
    glVertex2f(410, 110);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();
    
// #43.1 (side of 42 behind 14)-right side
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.6,0.5);    
    glVertex2f(148, 275);	// Bottom-left vertex
    glVertex2f(211, 235);     // bottom right vertex
    glVertex2f(197, 167);     // top right vertex
    glVertex2f(156, 160);	//top left vertex
    
    glEnd();
    
// #43.2(rest behind 14)-back
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.5,0.4);    
    glVertex2f(196, 244); 	// Bottom-left vertex
    glVertex2f(296, 284);     // bottom right vertex
    glVertex2f(275, 125);    // top right vertex
    glVertex2f(196, 191);	//top left vertex
    
    glEnd();
    
    // #43.2(rest behind 14)-roof
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.4,0.3);    
    glVertex2f(238, 205);	// Bottom-left vertex
    glVertex2f(275, 171);    // bottom right vertex
    glVertex2f(275, 125);    // top right vertex
    glVertex2f(196, 191);	//top left vertex
    
    glEnd();
    
    // #12
    glBegin(GL_POLYGON);  // Use GL_POLYGON for filled shapes
    glColor3f(0.8, 0.8, 0.8); // Light gray color
    glVertex2f(256, 546);     // Bottom-left vertex
    glVertex2f(307, 569);     // Bottom-right vertex
    glVertex2f(317, 195);     // Top-right vertex
    glVertex2f(272, 221);     // Top-left vertex
    glEnd();

    // #13
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.8,0.7);
    glVertex2f(272, 221);     // Bottom-left vertex
    glVertex2f(317, 195);     // Bottom-right vertex
    glVertex2f(321, 69);     // Top-right vertex
    glVertex2f(275, 104);     // Top-left vertex
    glEnd();

    // #14
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.8,0.7);
    glVertex2f(184, 194);     // Bottom-left vertex
    glVertex2f(276, 125);     // Bottom-right vertex
    glVertex2f(275, 104);     // Top-right vertex
    glVertex2f(183, 178);     // Top-left vertex
    glEnd();

    // #14.1 (shape under #14)
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.7,0.6);
    glVertex2f(189, 199);     // Bottom-left vertex
    glVertex2f(276, 132);     // Bottom-right vertex
    glVertex2f(276, 125);     // Top-right vertex
    glVertex2f(184, 194);     // Top-left vertex
    glEnd();

    // #15
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(262, 606);     // Bottom-left vertex
    glVertex2f(304, 628);     // Bottom-right vertex
    glVertex2f(306, 569);     // Top-right vertex
    glVertex2f(264, 550);     // Top-left vertex
    glEnd();

    // #16
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(260, 620);     // Bottom-left vertex
    glVertex2f(304, 642);     // Bottom-right vertex
    glVertex2f(304, 628);     // Top-right vertex
    glVertex2f(262, 606);     // Top-left vertex
    glEnd();

    // #17
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(175, 623);     // Bottom-left vertex
    glVertex2f(262, 606);     // Bottom-right vertex
    glVertex2f(265, 539);     // Top-right vertex
    glVertex2f(180, 553);     // Top-left vertex
    glEnd();

    // #18
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(175, 637);     // Bottom-left vertex
    glVertex2f(260, 620);     // Bottom-right vertex
    glVertex2f(262, 606);     // Top-right vertex
    glVertex2f(175, 624);     // Top-left vertex
    glEnd();
    

    // #19
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(54, 615);     // Bottom-left vertex
    glVertex2f(175, 624);     // Bottom-right vertex
    glVertex2f(180, 553);     // Top-right vertex
    glVertex2f(62, 545);     // Top-left vertex
    glEnd();
    

    // #20
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(52, 628);     // Bottom-left vertex
    glVertex2f(175, 637);     // Bottom-right vertex
    glVertex2f(175, 624);     // Top-right vertex
    glVertex2f(54, 615);     // Top-left vertex
    glEnd();


    // #21
    glBegin(GL_POLYGON);
    glColor3f(0.75,0.75,0.75);
    glVertex2f(42, 593);     // Bottom-left vertex
    glVertex2f(54, 615);     // Bottom-right vertex
    glVertex2f(62, 545);     // Top-right vertex
    glVertex2f(43, 528);     // Top-left vertex
    glEnd();


    // #22
    glBegin(GL_POLYGON);
    glColor3f(0.65,0.65,0.65);
    glVertex2f(42, 601);     // Bottom-left vertex
    glVertex2f(52, 628);     // Bottom-right vertex
    glVertex2f(54, 615);     // Top-right vertex
    glVertex2f(42, 593);     // Top-left vertex
    glEnd();


    // #23
    glBegin(GL_POLYGON);  
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(179, 553);     // Bottom-left vertex
    glVertex2f(265, 539);     // Bottom-right vertex
    glVertex2f(266, 475);     // Top-right vertex
    glVertex2f(186, 486);     // Top-left vertex
    glEnd();

    // #24
    glBegin(GL_POLYGON); 
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(62, 545);     // Bottom-left vertex
    glVertex2f(180, 553);     // Bottom-right vertex
    glVertex2f(186, 486);     // Top-right vertex
    glVertex2f(65, 481);     // Top-left vertex
    glEnd();

    // #25
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.85,0.85);
    glVertex2f(43, 528);     // Bottom-left vertex
    glVertex2f(62, 545);     // Bottom-right vertex
    glVertex2f(65, 481);     // Top-right vertex
    glVertex2f(43, 465);     // Top-left vertex
    glEnd();

    // #26
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(189, 487);     // Bottom-left vertex
    glVertex2f(272, 475);     // Bottom-right vertex
    glVertex2f(272, 458);     // Top-right vertex
    glVertex2f(189, 469);     // Top-left vertex
    glEnd();

    // #27
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(65, 481);     // Bottom-left vertex
    glVertex2f(189, 487);     // Bottom-right vertex
    glVertex2f(189, 469);     // Top-right vertex
    glVertex2f(65, 464);     // Top-left vertex
    glEnd();

    // #28
    glBegin(GL_POLYGON);
    glColor3f(0.65,0.65,0.65);
    glVertex2f(43, 465);     // Bottom-left vertex
    glVertex2f(65, 481);     // Bottom-right vertex
    glVertex2f(65, 464);     // Top-right vertex
    glVertex2f(45, 453);     // Top-left vertex
    glEnd();

// #39
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.8,0.7);
    glVertex2f(73, 452);     // Bottom-left vertex
    glVertex2f(118, 449);     // Bottom-right vertex
    glVertex2f(132, 306);     // Top-right vertex
    glVertex2f(92, 302);     // Top-left vertex
    glEnd();

    // #39.1 (shape under #39)
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.7,0.6);
    glVertex2f(65, 464);     // Bottom-left vertex
    glVertex2f(98, 464);     // Bottom-right vertex
    glVertex2f(118, 449);     // Top-right vertex
    glVertex2f(45, 453);     // Top-left vertex
    glEnd();
    
    // #29
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(98, 464);     // Bottom-left vertex
    glVertex2f(177, 467);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(170, 362);     // Top-left vertex
    glEnd();

    // #30
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(241, 463);     // Bottom-left vertex
    glVertex2f(263, 459);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(247, 364);     // Top-left vertex
    glEnd();

    // #31
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(177, 467);     // Bottom-left vertex
    glVertex2f(241, 463);     // Bottom-right vertex
    glVertex2f(247, 364);     // Top-right vertex
    glEnd();

    // #32
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.8,0.7);
    glVertex2f(137, 415);     // Bottom-left vertex
    glVertex2f(165, 369);     // Bottom-right vertex
    glVertex2f(166, 353);     // Top-right vertex
    glVertex2f(142, 350);     // Top-left vertex
    glEnd();

    // #33
    glBegin(GL_POLYGON);  
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(166, 362);     // Bottom-left vertex
    glVertex2f(267, 323);     // Bottom-right vertex
    glVertex2f(271, 310);     // Top-right vertex
    glVertex2f(167, 353);     // Top-left vertex
    glEnd();

    // #34
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(166, 353);     // Bottom-left vertex
    glVertex2f(271, 310);     // Bottom-right vertex
    glVertex2f(248, 302);     // Top-right vertex
    glVertex2f(142, 350);     // Top-left vertex
    glEnd();

    // #35
    glBegin(GL_POLYGON); 
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(248, 302);     // Bottom-left vertex
    glVertex2f(271, 310);     // Bottom-right vertex
    glVertex2f(272, 221);     // Top-right vertex
    glVertex2f(251, 210);     // Top-left vertex
    glEnd();

    // #36
    glBegin(GL_POLYGON);  
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(126, 359);     // Bottom-left vertex
    glVertex2f(248, 302);     // Bottom-right vertex
    glVertex2f(251, 210);     // Top-right vertex
    glVertex2f(134, 282);     // Top-left vertex
    glEnd();

    // #37
    glBegin(GL_POLYGON);  
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(184, 316);     // Bottom-left vertex
    glVertex2f(193, 310);     // Bottom-right vertex
    glVertex2f(193, 302);     // Top-right vertex
    glVertex2f(184, 308);     // Top-left vertex
    glEnd();

    // #38
    glBegin(GL_POLYGON);  
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(119, 437);     // Bottom-left vertex
    glVertex2f(137, 415);     // Bottom-right vertex
    glVertex2f(142, 350);     // Top-right vertex
    glVertex2f(126, 359);     // Top-left vertex
    glEnd();


    

    // #40
    glBegin(GL_POLYGON);  
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(48, 377);     // Bottom-left vertex
    glVertex2f(83, 366);     // Bottom-right vertex
    glVertex2f(92, 302);     // Top-right vertex
    glVertex2f(52, 332);     // Top-left vertex
    glEnd();

    // #40.1 (connecting shape to #40)
    glBegin(GL_POLYGON);  
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(62, 452);     // Bottom-left vertex
    glVertex2f(73, 452);     // Bottom-right vertex
    glVertex2f(83, 366);     // Top-right vertex
    glVertex2f(69, 370);     // Top-left vertex
    glEnd();

    // #41
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.7,0.6);
    glVertex2f(92, 302);     // Bottom-left vertex
    glVertex2f(132, 306);     // Bottom-right vertex
    glVertex2f(140, 213);     // Top-right vertex
    glVertex2f(96, 245);     // Top-left vertex
    glEnd();

    // #42
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(96, 245);     // Bottom-left vertex
    glVertex2f(140, 213);     // Bottom-right vertex
    glVertex2f(156, 160);     // Top-right vertex
    glVertex2f(87, 224);     // Top-left vertex
    glEnd();

    // #42.1 (connecting left shape to #42)
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(80, 310);     // Bottom-left vertex
    glVertex2f(92, 302);     // Bottom-right vertex
    glVertex2f(96, 245);     // Top-right vertex
    glVertex2f(87, 224);     // Top-left vertex
    glEnd();

    // #42.2 (connecting right shape to #42)
    glBegin(GL_POLYGON);
    glColor3f(1,0.9,0.8);
    glVertex2f(134, 282);     // Bottom-left vertex
    glVertex2f(148, 274);     // Bottom-right vertex
    glVertex2f(156, 160);     // Top-right vertex
    glVertex2f(140, 213);     // Top-left vertex
    glEnd();

    
	
    
        // #44
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.7f, 0.6f);  // change outline color to sky blue
    glVertex2f(258, 215);     // left vertex
    glVertex2f(274, 198);     // right vertex  
    glVertex2f(272, 221);
    glEnd();

    // #45
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(431, 345);     // Bottom-left vertex
    glVertex2f(485, 337);     // Bottom-right vertex
    glVertex2f(485, 323);     // Top-right vertex
    glVertex2f(431, 332);     // Top-left vertex
    glEnd();

    // #46
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(430, 325);     // Bottom-left vertex
    glVertex2f(485, 315);     // Bottom-right vertex
    glVertex2f(485, 308);     // Top-right vertex
    glVertex2f(429, 318);     // Top-left vertex
    glEnd();


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Enable blending for transparent textures
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Use the texture shader
    glUseProgram(shaderProgram);

    GLint textureUniform = glGetUniformLocation(shaderProgram, "texture");
    glUniform1i(textureUniform, 0);

    GLint opacityUniform = glGetUniformLocation(shaderProgram, "opacity");
    glUniform1f(opacityUniform, 0.5);


    // #1
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(307, 569);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(428, 538);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(433, 217);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(317, 195);
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
}

    // #2
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(329, 446);     // Bottom-left vertex
    glTexCoord2f(1.0f, 0.0f); glVertex2f(421, 450);     // Bottom-right vertex
    glTexCoord2f(1.0f, 1.0f); glVertex2f(421, 329);     // Top-right vertex
    glTexCoord2f(0.0f, 1.0f); glVertex2f(331, 321);     // Top-left vertex
    glEnd();
    
    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #3
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(412, 451);     // Bottom-left vertex
    glTexCoord2f(1.0f, 0.0f); glVertex2f(421, 450);     // Bottom-right vertex
    glTexCoord2f(1.0f, 1.0f); glVertex2f(421, 329);     // Top-right vertex
    glTexCoord2f(0.0f, 1.0f); glVertex2f(412, 333);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #4
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(332, 326);     // Bottom-left vertex
    glTexCoord2f(1.0f, 0.0f); glVertex2f(412, 333);     // Bottom-right vertex
    glTexCoord2f(1.0f, 1.0f); glVertex2f(421, 329);     // Top-right vertex
    glTexCoord2f(0.0f, 1.0f); glVertex2f(331, 321);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #5
    glBegin(GL_QUADS);
    glVertex2f(304, 628);  // Bottom-left vertex
    glVertex2f(427, 595);  // Bottom-right vertex
    glVertex2f(428, 538);  // Top-right vertex
    glVertex2f(306, 569);  // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #6
    glBegin(GL_QUADS);
    glVertex2f(304, 642);     // Bottom-left vertex
    glVertex2f(427, 611);     // Bottom-right vertex
    glVertex2f(427, 595);     // Top-right vertex
    glVertex2f(304, 628);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #7
    glBegin(GL_QUADS);
    glVertex2f(427, 611);     // Bottom-left vertex
    glVertex2f(485, 643);     // Bottom-right vertex
    glVertex2f(485, 73);     // Top-right vertex
    glVertex2f(431, 94);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #8
    glBegin(GL_QUADS);
    glVertex2f(317, 195); // Bottom-left vertex
    glVertex2f(433, 217); // Bottom-right vertex
    glVertex2f(431, 94);  // Top-right vertex
    glVertex2f(322, 67);  // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #9
    glBegin(GL_QUADS);
    glVertex2f(335, 189);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #10
    glBegin(GL_QUADS);
    glVertex2f(409, 203);     // Bottom-left vertex
    glVertex2f(418, 203);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(410, 110);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #11
    glBegin(GL_QUADS);
    glVertex2f(336, 95);     // Bottom-left vertex
    glVertex2f(410, 110);     // Bottom-right vertex
    glVertex2f(418, 106);     // Top-right vertex
    glVertex2f(337, 90);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
// #43.1 (side of 42 behind 14)-right side
    glBegin(GL_POLYGON);
    glVertex2f(148, 275);	// Bottom-left vertex
    glVertex2f(211, 235);     // bottom right vertex
    glVertex2f(197, 167);     // top right vertex
    glVertex2f(156, 160);	//top left vertex
    
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
// #43.2(rest behind 14)-back
    glBegin(GL_QUADS);
    glVertex2f(196, 244); 	// Bottom-left vertex
    glVertex2f(296, 284);     // bottom right vertex
    glVertex2f(275, 125);    // top right vertex
    glVertex2f(196, 191);	//top left vertex
    
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
    // #43.2(rest behind 14)-roof
    glBegin(GL_QUADS);
    glVertex2f(238, 205);	// Bottom-left vertex
    glVertex2f(275, 171);    // bottom right vertex
    glVertex2f(275, 125);    // top right vertex
    glVertex2f(196, 191);	//top left vertex
    
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
    // #12
    glBegin(GL_QUADS);  // Use GL_POLYGON for filled shapes
    glVertex2f(256, 546);     // Bottom-left vertex
    glVertex2f(307, 569);     // Bottom-right vertex
    glVertex2f(317, 195);     // Top-right vertex
    glVertex2f(272, 221);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #13
    glBegin(GL_QUADS);
    glVertex2f(272, 221);     // Bottom-left vertex
    glVertex2f(317, 195);     // Bottom-right vertex
    glVertex2f(321, 69);     // Top-right vertex
    glVertex2f(275, 104);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
    // #14
    glBegin(GL_QUADS);
    glVertex2f(184, 194);     // Bottom-left vertex
    glVertex2f(276, 125);     // Bottom-right vertex
    glVertex2f(275, 104);     // Top-right vertex
    glVertex2f(183, 178);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #14.1 (shape under #14)
    glBegin(GL_QUADS);
    glVertex2f(189, 199);     // Bottom-left vertex
    glVertex2f(276, 132);     // Bottom-right vertex
    glVertex2f(276, 125);     // Top-right vertex
    glVertex2f(184, 194);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #15
    glBegin(GL_QUADS);
    glVertex2f(262, 606);     // Bottom-left vertex
    glVertex2f(304, 628);     // Bottom-right vertex
    glVertex2f(306, 569);     // Top-right vertex
    glVertex2f(264, 550);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #16
    glBegin(GL_QUADS);
    glVertex2f(260, 620);     // Bottom-left vertex
    glVertex2f(304, 642);     // Bottom-right vertex
    glVertex2f(304, 628);     // Top-right vertex
    glVertex2f(262, 606);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #17
    glBegin(GL_QUADS);
    glVertex2f(175, 623);     // Bottom-left vertex
    glVertex2f(262, 606);     // Bottom-right vertex
    glVertex2f(265, 539);     // Top-right vertex
    glVertex2f(180, 553);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #18
    glBegin(GL_QUADS);
    glVertex2f(175, 637);     // Bottom-left vertex
    glVertex2f(260, 620);     // Bottom-right vertex
    glVertex2f(262, 606);     // Top-right vertex
    glVertex2f(175, 624);     // Top-left vertex
    glEnd();
    
    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #19
    glBegin(GL_QUADS);
    glVertex2f(54, 615);     // Bottom-left vertex
    glVertex2f(175, 624);     // Bottom-right vertex
    glVertex2f(180, 553);     // Top-right vertex
    glVertex2f(62, 545);     // Top-left vertex
    glEnd();
    
    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #20
    glBegin(GL_QUADS);
    glVertex2f(52, 628);     // Bottom-left vertex
    glVertex2f(175, 637);     // Bottom-right vertex
    glVertex2f(175, 624);     // Top-right vertex
    glVertex2f(54, 615);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #21
    glBegin(GL_QUADS);
    glVertex2f(42, 593);     // Bottom-left vertex
    glVertex2f(54, 615);     // Bottom-right vertex
    glVertex2f(62, 545);     // Top-right vertex
    glVertex2f(43, 528);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #22
    glBegin(GL_QUADS);
    glVertex2f(42, 601);     // Bottom-left vertex
    glVertex2f(52, 628);     // Bottom-right vertex
    glVertex2f(54, 615);     // Top-right vertex
    glVertex2f(42, 593);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #23
    glBegin(GL_QUADS);  
    glVertex2f(179, 553);     // Bottom-left vertex
    glVertex2f(265, 539);     // Bottom-right vertex
    glVertex2f(266, 475);     // Top-right vertex
    glVertex2f(186, 486);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #24
    glBegin(GL_QUADS); 
    glVertex2f(62, 545);     // Bottom-left vertex
    glVertex2f(180, 553);     // Bottom-right vertex
    glVertex2f(186, 486);     // Top-right vertex
    glVertex2f(65, 481);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #25
    glBegin(GL_QUADS);
    glVertex2f(43, 528);     // Bottom-left vertex
    glVertex2f(62, 545);     // Bottom-right vertex
    glVertex2f(65, 481);     // Top-right vertex
    glVertex2f(43, 465);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #26
    glBegin(GL_QUADS);
    glVertex2f(189, 487);     // Bottom-left vertex
    glVertex2f(272, 475);     // Bottom-right vertex
    glVertex2f(272, 458);     // Top-right vertex
    glVertex2f(189, 469);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #27
    glBegin(GL_QUADS);
    glVertex2f(65, 481);     // Bottom-left vertex
    glVertex2f(189, 487);     // Bottom-right vertex
    glVertex2f(189, 469);     // Top-right vertex
    glVertex2f(65, 464);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #28
    glBegin(GL_QUADS);
    glVertex2f(43, 465);     // Bottom-left vertex
    glVertex2f(65, 481);     // Bottom-right vertex
    glVertex2f(65, 464);     // Top-right vertex
    glVertex2f(45, 453);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #39
    glBegin(GL_QUADS);
    glVertex2f(73, 452);     // Bottom-left vertex
    glVertex2f(118, 449);     // Bottom-right vertex
    glVertex2f(132, 306);     // Top-right vertex
    glVertex2f(92, 302);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #39.1 (shape under #39)
    glBegin(GL_QUADS);
    glVertex2f(65, 464);     // Bottom-left vertex
    glVertex2f(98, 464);     // Bottom-right vertex
    glVertex2f(118, 449);     // Top-right vertex
    glVertex2f(45, 453);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();
    
    // #29
    glBegin(GL_QUADS);
    glVertex2f(98, 464);     // Bottom-left vertex
    glVertex2f(177, 467);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(170, 362);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #30
    glBegin(GL_QUADS);
    glVertex2f(241, 463);     // Bottom-left vertex
    glVertex2f(263, 459);     // Bottom-right vertex
    glVertex2f(267, 324);     // Top-right vertex
    glVertex2f(247, 364);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #31
    glBegin(GL_QUADS);
    glVertex2f(177, 467);     // Bottom-left vertex
    glVertex2f(241, 463);     // Bottom-right vertex
    glVertex2f(247, 364);     // Top-right vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #32
    glBegin(GL_QUADS);
    glVertex2f(137, 415);     // Bottom-left vertex
    glVertex2f(165, 369);     // Bottom-right vertex
    glVertex2f(166, 353);     // Top-right vertex
    glVertex2f(142, 350);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #33
    glBegin(GL_QUADS);  
    glVertex2f(166, 362);     // Bottom-left vertex
    glVertex2f(267, 323);     // Bottom-right vertex
    glVertex2f(271, 310);     // Top-right vertex
    glVertex2f(167, 353);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #34
    glBegin(GL_QUADS);
    glVertex2f(166, 353);     // Bottom-left vertex
    glVertex2f(271, 310);     // Bottom-right vertex
    glVertex2f(248, 302);     // Top-right vertex
    glVertex2f(142, 350);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #35
    glBegin(GL_QUADS); 
    glVertex2f(248, 302);     // Bottom-left vertex
    glVertex2f(271, 310);     // Bottom-right vertex
    glVertex2f(272, 221);     // Top-right vertex
    glVertex2f(251, 210);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #36
    glBegin(GL_QUADS);  
    glVertex2f(126, 359);     // Bottom-left vertex
    glVertex2f(248, 302);     // Bottom-right vertex
    glVertex2f(251, 210);     // Top-right vertex
    glVertex2f(134, 282);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #37
    glBegin(GL_QUADS);  
    glVertex2f(184, 316);     // Bottom-left vertex
    glVertex2f(193, 310);     // Bottom-right vertex
    glVertex2f(193, 302);     // Top-right vertex
    glVertex2f(184, 308);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #38
    glBegin(GL_QUADS);  
    glVertex2f(119, 437);     // Bottom-left vertex
    glVertex2f(137, 415);     // Bottom-right vertex
    glVertex2f(142, 350);     // Top-right vertex
    glVertex2f(126, 359);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #40
    glBegin(GL_QUADS);  
    glVertex2f(48, 377);     // Bottom-left vertex
    glVertex2f(83, 366);     // Bottom-right vertex
    glVertex2f(92, 302);     // Top-right vertex
    glVertex2f(52, 332);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #40.1 (connecting shape to #40)
    glBegin(GL_QUADS);  
    glVertex2f(62, 452);     // Bottom-left vertex
    glVertex2f(73, 452);     // Bottom-right vertex
    glVertex2f(83, 366);     // Top-right vertex
    glVertex2f(69, 370);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #41
    glBegin(GL_QUADS);
    glVertex2f(92, 302);     // Bottom-left vertex
    glVertex2f(132, 306);     // Bottom-right vertex
    glVertex2f(140, 213);     // Top-right vertex
    glVertex2f(96, 245);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #42
    glBegin(GL_QUADS);
    glVertex2f(96, 245);     // Bottom-left vertex
    glVertex2f(140, 213);     // Bottom-right vertex
    glVertex2f(156, 160);     // Top-right vertex
    glVertex2f(87, 224);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #42.1 (connecting left shape to #42)
    glBegin(GL_QUADS);
    glVertex2f(80, 310);     // Bottom-left vertex
    glVertex2f(92, 302);     // Bottom-right vertex
    glVertex2f(96, 245);     // Top-right vertex
    glVertex2f(87, 224);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #42.2 (connecting right shape to #42)
    glBegin(GL_QUADS);
    glVertex2f(134, 282);     // Bottom-left vertex
    glVertex2f(148, 274);     // Bottom-right vertex
    glVertex2f(156, 160);     // Top-right vertex
    glVertex2f(140, 213);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #44
    glBegin(GL_QUADS);
    glVertex2f(258, 215);     // left vertex
    glVertex2f(274, 198);     // right vertex  
    glVertex2f(272, 221);
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #45
    glBegin(GL_QUADS);
    glVertex2f(431, 345);     // Bottom-left vertex
    glVertex2f(485, 337);     // Bottom-right vertex
    glVertex2f(485, 323);     // Top-right vertex
    glVertex2f(431, 332);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();

    // #46
    glBegin(GL_QUADS);
    glVertex2f(430, 325);     // Bottom-left vertex
    glVertex2f(485, 315);     // Bottom-right vertex
    glVertex2f(485, 308);     // Top-right vertex
    glVertex2f(429, 318);     // Top-left vertex
    glEnd();

    // Reset to default shader and disable texturing
    glUseProgram(0);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable blending
    glDisable(GL_BLEND);

    glutSwapBuffers();


void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(485, 662);
    glutCreateWindow("Project 4 Rendering");

    glewInit();

    loadTexture();
    setupShaders();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
