#pragma once

#include "VBO.h"


// VAO : Vertex Array Object

class VAO
{
public :
	GLuint m_ID;
	VAO();

	void linkVBO(VBO vbo, GLuint layout);

	void bind();
	void unBind();
	void terminate();
};

