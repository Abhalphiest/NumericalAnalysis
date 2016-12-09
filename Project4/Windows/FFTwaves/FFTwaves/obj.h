#pragma once

#include<sstream>
#include<fstream>
#include<vector>

#include "glm-0.9.2.6/glm/glm.hpp"
#include "glm-0.9.2.6/glm/gtc/matrix_transform.hpp"
#include "glm-0.9.2.6/glm/gtc/type_ptr.hpp"

#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;
};

void loadObj(const char* filename, std::vector<Vertex>& verts, std::vector<UINT>& indices);
void setupMesh(const char* filename, GLuint &vao, GLuint &vbo, GLuint &ibo, GLuint &numIndices);