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
#include<vector>
#include "structs.h"
#include "ocean.h"
#include "skybox.h"
#include "objects.h"
//REMOVE FOR SUBMISSION
#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>

// dimensions of the drawing window
const int w_width = 600;
const int w_height = 600;

//global for simplicity for now
ocean* myOcean;
skybox mySkybox;
float rotx=0.0f, roty=15.0f; //for camera


//initialize GLUT, set up callbacks, etc
bool init(int argc, char** argv);
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
	myOcean = new ocean(64, 0.0001f, vector2(32.0f, 32.0f), 64, false);
	mySkybox.setupSkybox();
	buildObjects();
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
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);
	glEnable(GL_DEPTH_TEST);
	return true;
}


void keyboard(unsigned char c, int i, int j)
{
	switch (c) {
	case 'w':
		rotx += 1.0;
		if (rotx >= 10.0)
			rotx = 10.0;
		break;
	case 's':
		rotx -= 1.0;
		if (rotx <= -30.0)
			rotx = -30.0;
		break;
	case 'd':
		roty += 1.0;
		if (roty >= 60.0)
			roty = 60.0;
		break;
	case 'a':
		roty -= 1.0;
		if (roty <= 10.0)
			roty = 10.0;
		break;
	}
}
void update()
{

		//hard code for now, for simplicity
		static glm::mat4 Projection = glm::perspective(45.0f, (float)w_width / (float)w_height, 0.1f, 1000.0f);
		static glm::mat4 View;
		static glm::mat4 Model = glm::mat4(1.0f);
		static glm::vec3 light_position;

		View = glm::mat4(1.0f);
		View = glm::rotate(View, rotx, glm::vec3(-1.0f, 0.0f, 0.0f));
		View = glm::rotate(View, roty, glm::vec3(0.0f, 1.0f, 0.0f));
		View = glm::translate(View, glm::vec3(10, -30, -5));
		light_position = glm::vec3(350.0f, 100.0f, -1000.0f);
		//get time since last frame
		float t1 = (float)(glutGet(GLUT_ELAPSED_TIME) / 1000.0);
		// rendering
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		myOcean->render(t1, light_position, Projection, View, Model);
		drawObjects(View,Projection,light_position);
		mySkybox.renderSkybox(View, Projection); //draw skybox last
												 // swap the buffers
		glutSwapBuffers();
	
	
}




