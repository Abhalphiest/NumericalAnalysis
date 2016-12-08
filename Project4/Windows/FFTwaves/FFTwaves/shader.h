#pragma once
#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

#include "complex.h"

char* loadFile(const char *filename);

void createProgram(GLuint& glProgram, GLuint& glShaderV, GLuint& glShaderF, const char* vertex_shader, const char* fragment_shader);
void releaseProgram(GLuint& glProgram, GLuint glShaderV, GLuint glShaderF);