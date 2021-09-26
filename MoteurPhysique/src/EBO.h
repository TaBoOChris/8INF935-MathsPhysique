#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class EBO
{

public:
	GLuint m_ID;

	EBO(GLuint* Indices, GLsizeiptr size);

	void bind();		// Bind the EBO
	void unBind();		// unBind the EBO
	void terminate();	// delete the EBO
};
