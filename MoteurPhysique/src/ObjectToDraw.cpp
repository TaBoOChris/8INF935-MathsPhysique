#include "ObjectToDraw.h"


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"

ObjectToDraw::ObjectToDraw()
{
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1 // Upper triangle
	};

	m_shaderProgram = new Shader("default.vert", "default.frag");	// Gen Shader obj with shaders default.vert and default.frag

	m_VAO = new VAO();	// Generates Vertex Array  Object
	m_VAO->bind();		// Bind Vertex Array  Object

	m_VBO = new VBO(vertices, sizeof(vertices));// Gen Vertex  Buffer Object, links it to vertices
	m_EBO = new EBO(indices, sizeof(indices));	// Gen Element Buffer Object, links it to indices


}

void ObjectToDraw::initialization()
{
	m_VAO->linkVBO(*m_VBO, 0); // Links VBO to VAO
	// Unbind all to prevent accidentally modifying them
	m_VAO->unBind();
	m_VBO->unBind();
	m_EBO->unBind();
}

void ObjectToDraw::terminate()
{
	// Delete all the objects we've created
	m_VAO->terminate();
	m_VBO->terminate();
	m_EBO->terminate();
	m_shaderProgram->terminate();
	
}

void ObjectToDraw::display()
{
	m_shaderProgram->activate();
	m_VAO->bind();
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);		// Draw the triangle using the GL_TRIANGLES primitive
}
