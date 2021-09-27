#include "VBO.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// VBO : Vertex Buffer Object

VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &this->m_ID);		// Generate VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->m_ID);	 //Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);	// Introduce the Vertices into the VBO

}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->m_ID);	 //Bind the VBO specifying it's a GL_ARRAY_BUFFER
}

void VBO::unBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::terminate()
{
	glDeleteBuffers(1, &this->m_ID);

}
