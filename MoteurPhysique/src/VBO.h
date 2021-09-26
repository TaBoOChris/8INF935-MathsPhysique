#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Vertex Buffer Object 
class VBO
{

public:
	GLuint m_ID;	// ref ID of the VBO

	VBO(GLfloat* vertices, GLsizeiptr size);	// COnstructor 

	void bind();		// Bind the VBO
	void unBind();		// unBind the VBO
	void terminate();	// delete the vbo
};

