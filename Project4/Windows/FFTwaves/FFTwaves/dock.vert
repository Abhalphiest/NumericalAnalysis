#version 330
 
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;
 
//uniforms
//uniform mat4 MVP;   //combined modelview projection matrix
//uniform float time; //elasped time
 
//shader constants
//const float amplitude = 0.125;
//const float frequency = 4;
//const float PI = 3.14159;
 
void main()
{
	gl_Position = position;
}