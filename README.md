# 310Project

Compile this code in a Linux environment.

Make sure the following files are downloaded and unzipped:
  - Project4.cpp
  - vertexShader.vs
  - fragmentShader.fs
  - drywall.jpeg

Place all included files inside your Linux directory.

To make sure all required libraries are installed, run the following commands:

  > sudo apt-get update

  > sudo apt-get install libglm-dev

  > sudo apt-get install libglu1-mesa-dev

  > sudo apt-get install mesa-common-dev

  > sudo apt-get install freeglut3-dev

  > sudo apt-get install libglew-dev

  > sudo apt-get install libsoil-dev

To create an executable, type the following command:

  > g++ -o p4 Project4.cpp -lGL -lGLU -lglut -lGLEW -lSOIL

To execute the program run the command:

  > ./p4
