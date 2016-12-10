#pragma once

#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include "SOIL\SOIL.h"

#include "glm-0.9.2.6/glm/glm.hpp"
#include "glm-0.9.2.6/glm/gtc/matrix_transform.hpp"
#include "glm-0.9.2.6/glm/gtc/type_ptr.hpp"

#include "obj.h"
#include "shader.h"



//laziness
void buildObjects();
void drawObjects(glm::mat4 View, glm::mat4 Projection, glm::vec3 light_pos);

#endif