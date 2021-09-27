#include "EBO.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// EBO : Element Buffer Object




EBO::EBO(std::vector<GLuint>& indices)
{
	glGenBuffers(1, &this->m_ID);		// Generate EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ID);	 //Bind the EBO specifying it's a GL_ARRAY_BUFFER
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);	// Introduce the Vertices into the EBO

}

void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ID);	 //Bind the VBO specifying it's a GL_ARRAY_BUFFER
}

void EBO::unBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::terminate()
{
	glDeleteBuffers(1, &this->m_ID);

}
