#pragma once

#include "VBO.h"


// VAO : Vertex Array Object

class VAO
{
public :
	GLuint m_ID;
	VAO();

	void linkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void bind();
	void unBind();
	void terminate();
};

