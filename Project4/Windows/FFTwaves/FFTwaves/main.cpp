// 
// File: main.cpp
// Author: Margaret Dorsey
//
//

#include "glm-0.9.2.6/glm/glm.hpp"
#include "glm-0.9.2.6/glm/gtc/matrix_transform.hpp"
#include "glm-0.9.2.6/glm/gtc/type_ptr.hpp"


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "ocean.h"

//REMOVE FOR SUBMISSION
#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>

// dimensions of the drawing window
const int w_width = 600;
const int w_height = 600;

//global for simplicity for now
ocean* myOcean;

//initialize GLUT, set up callbacks, etc
bool init(int argc, char** argv);
//our display function
void draw();
//our keyboard input function
void keyboard(unsigned char c, int i, int j);
//our update function
void update();

int main(int argc, char**argv)
{
	bool success = init(argc, argv);
	if (!success)
	{
		exit(1);
	}
	myOcean = new ocean(64, 0.0005f, vector2(32.0f, 32.0f), 64, true);
	glutMainLoop(); //enter our loop
	myOcean->release();
	delete myOcean;
	return 0;
}

bool init(int argc, char** argv)
{
	//initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	//make window
	glutInitWindowSize(w_width, w_height);
	glutCreateWindow("Margaret Dorsey Final Project");
	//initialize GLEW
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		fprintf(stderr, "GLEW initialization error: %s\n", glewGetErrorString(err));
		return false;
	}

	//set up callbacks
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);
	return true;
}

void draw()
{

}
void keyboard(unsigned char c, int i, int j)
{

}
void update()
{

	//hard code for now, for simplicity
	static glm::mat4 Projection = glm::perspective(45.0f, (float)w_width / (float)w_height, 0.1f, 1000.0f);
	static glm::mat4 View = glm::mat4(1.0f);
	static glm::mat4 Model = glm::mat4(1.0f);
	static glm::vec3 light_position;
	//get time since last frame
	float t1 = (float)glutGet(GLUT_ELAPSED_TIME);
	// rendering
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myOcean->render(t1, light_position, Projection, View, Model, true);

	// swap the buffers
	glutSwapBuffers();
}
