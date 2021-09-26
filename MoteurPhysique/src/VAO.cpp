#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &this->m_ID);	// Generate VAO
}

void VAO::linkVBO(VBO VBO, GLuint layout)
{
	VBO.bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);	// Configure the Vertex Attribute so that OpenGL knows how to read it
	glEnableVertexAttribArray(layout);			// Enable the Vertex Attribute so that OpenGL knows how to use it
	VBO.unBind();
}

void VAO::bind()
{
	glBindVertexArray(this->m_ID);	// Make the VAO the current Vertex Array Object by binding it
}

void VAO::unBind()
{
	glBindVertexArray(0);
}

void VAO::terminate()
{
	glDeleteVertexArrays(1, &this->m_ID);
}
