#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{

public :
	GLuint m_ID;	// ref ID of the shader
	
	Shader(const char* vertexFile, const char* fragmentFile);	// Constructor

	void activate();	// Activate the shader
	void terminate();	// delete the shader 

private:
	
	void compileErrors(unsigned int shader, const char* type); // check if shaders have compiled properly
};

