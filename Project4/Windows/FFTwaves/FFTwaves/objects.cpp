#include "objects.h"

//horrible coding practice, but it does the job for this little toy demo
//shaders
GLuint objectProgram, objectVS, objectFS;
//dock and teapot
GLuint dockvao, dockvbo, dockibo, docknumIndices, dockTexture;
glm::mat4 dM; //dock model matrix

GLuint teapotvao, teapotvbo, teapotibo, teapotnumIndices, teapotTexture;
glm::mat4 tM; //teapot model matrix

void buildObjects()
{
	setupMesh("dock.obj", dockvao, dockvbo, dockibo, docknumIndices);
	setupMesh("teapot.obj", teapotvao, teapotvbo, teapotibo, teapotnumIndices);
	createProgram(objectProgram, objectVS, objectFS, "objects.vert", "objects.frag");
	dM = glm::mat4(1.0);
	dM = glm::translate(dM, glm::vec3(-10, 29.5, 0)); //hard coded because I'm a jerk
	tM = glm::mat4(1.0);
	tM = glm::translate(tM, glm::vec3(-10, 29.5, 4.25));
	tM = glm::scale(tM, glm::vec3(.02f));

	//set up textures
	glActiveTexture(GL_TEXTURE0);
	dockTexture = SOIL_load_OGL_texture
	(
		"woodtexture.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y //no need to bother with mip mapping, etc
	);
	glBindTexture(GL_TEXTURE_2D, dockTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glActiveTexture(GL_TEXTURE0);
	teapotTexture = SOIL_load_OGL_texture
	(
		"uvtexture.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y //no need to bother with mip mapping, etc
	);
	glBindTexture(GL_TEXTURE_2D, teapotTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


void drawObjects(glm::mat4 View, glm::mat4 Projection, glm::vec3 light_pos)
{
	GLuint light_position = glGetUniformLocation(objectProgram, "light_position");
	GLuint textureLoc = glGetUniformLocation(objectProgram, "Texture");
	glUniform3f(light_position, light_pos.x, light_pos.y, light_pos.z);
	//dock goes first
	glUseProgram(objectProgram);
	GLuint m = glGetUniformLocation(objectProgram, "Model");
	glUniformMatrix4fv(m, 1, GL_FALSE, glm::value_ptr(dM));
	GLuint v = glGetUniformLocation(objectProgram, "View");
	glUniformMatrix4fv(v, 1, GL_FALSE, glm::value_ptr(View));
	GLuint p = glGetUniformLocation(objectProgram, "Projection");
	glUniformMatrix4fv(p, 1, GL_FALSE, glm::value_ptr(Projection));

	//pass in texture info
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, dockTexture);
	glUniform1i(textureLoc, 0);
	//pass in vertex info
	glBindVertexArray(dockvao);
	glBindBuffer(GL_ARRAY_BUFFER, dockvbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, dockibo);
	//the connection between attributes, interleaved data
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);                       //send positions on pipe 0
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 3));       //send normals on pipe 1
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 6));     //send uv on pipe 2
	glDrawElements(GL_TRIANGLES, docknumIndices, GL_UNSIGNED_INT, 0);


	//now the teapot
	//dock goes first
	glUseProgram(objectProgram);
	m = glGetUniformLocation(objectProgram, "Model");
	glUniformMatrix4fv(m, 1, GL_FALSE, glm::value_ptr(tM));
	v = glGetUniformLocation(objectProgram, "View");
	glUniformMatrix4fv(v, 1, GL_FALSE, glm::value_ptr(View));
	p = glGetUniformLocation(objectProgram, "Projection");
	glUniformMatrix4fv(p, 1, GL_FALSE, glm::value_ptr(Projection));
	glBindVertexArray(teapotvao);
	glBindBuffer(GL_ARRAY_BUFFER, teapotvbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, teapotibo);

	//pass in texture info
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, teapotTexture);
	glUniform1i(textureLoc, 0);
	//the connection between attributes, interleaved data
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);                       //send positions on pipe 0
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 3));       //send normals on pipe 1
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 6));     //send uv on pipe 2
	glDrawElements(GL_TRIANGLES, teapotnumIndices, GL_UNSIGNED_INT, 0);
}