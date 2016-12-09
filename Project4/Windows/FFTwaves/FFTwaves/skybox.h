#pragma once
#include <windows.h>
#include "SOIL\SOIL.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <string>



#include "glm-0.9.2.6/glm/glm.hpp"
#include "glm-0.9.2.6/glm/gtc/matrix_transform.hpp"
#include "glm-0.9.2.6/glm/gtc/type_ptr.hpp"
#include "shader.h"
class skybox
{
	GLuint texture;
	GLuint skyboxVAO, skyboxVBO;
	GLuint skyboxProgram, skyboxVS, skyboxPS;
	char* faces[6] = {"skybox/nightsky_right.jpg","skybox/nightsky_left.jpg","skybox/nightsky_top.jpg","skybox/nightsky_bottom.jpg",
		"skybox/nightsky_back.jpg", "skybox/nightsky_front.jpg" };
public:
	void setupSkybox();
	void renderSkybox(glm::mat4 View, glm::mat4 Projection);

};