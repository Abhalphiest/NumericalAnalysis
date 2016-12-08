#pragma once
#include <windows.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include "complex.h"
#include "vector.h"

struct vertex_ocean {
	GLfloat   x, y, z; // vertex
	GLfloat  nx, ny, nz; // normal
	GLfloat   a, b, c; // htilde0
	GLfloat  _a, _b, _c; // htilde0mk conjugate
	GLfloat  ox, oy, oz; // original position
};




struct complex_vector_normal {	// structure used with discrete fourier transform
	complex h;		// wave height
	vector2 D;		// displacement
	vector3 n;		// normal
};


