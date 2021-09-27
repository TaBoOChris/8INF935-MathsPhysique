#include "ObjectToDraw.h"


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

#include "Shader.h"
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"
#include "Texture.h"

ObjectToDraw::ObjectToDraw()
{
	// Vertices coordinates
	GLfloat vertices[] =
	{ //     COORDINATES     /        COLORS      /   TexCoord  //
		-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
		-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
		 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
		 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 2, 1, // Upper triangle
		0, 3, 2 // Lower triangle
	};

	m_shaderProgram = new Shader("default.vert", "default.frag");	// Gen Shader obj with shaders default.vert and default.frag

	m_VAO = new VAO();	// Generates Vertex Array  Object
	m_VAO->bind();		// Bind Vertex Array  Object

	m_VBO = new VBO(vertices, sizeof(vertices));// Gen Vertex  Buffer Object, links it to vertices
	m_EBO = new EBO(indices, sizeof(indices));	// Gen Element Buffer Object, links it to indices


}

void ObjectToDraw::initialization()
{
	m_VAO->linkAttrib(*m_VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0); // Links VBO to VAO
	m_VAO->linkAttrib(*m_VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float) )); // Links VBO to VAO
	m_VAO->linkAttrib(*m_VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float) )); // Links VBO to VAO

	// Unbind all to prevent accidentally modifying them
	m_VAO->unBind();
	m_VBO->unBind();
	m_EBO->unBind();

	// gets ID of the Uniform called 'scale'
	m_uniID = glGetUniformLocation(m_shaderProgram->m_ID, "scale");

	// Texture
	m_texture = new Texture("fiery.png", GL_TEXTURE_2D, GL_TEXTURE0,GL_RGBA,GL_UNSIGNED_BYTE);
	m_texture->texUnit(*m_shaderProgram, "tex0", 0);

}

void ObjectToDraw::terminate()
{
	// Delete all the objects we've created
	m_VAO->terminate();
	m_VBO->terminate();
	m_EBO->terminate();
	m_texture->terminate();
	m_shaderProgram->terminate();
	
}

void ObjectToDraw::display()
{
	m_shaderProgram->activate();	// Telle OpenGL wich shader we want to use
	glUniform1f(m_uniID, 0.5f);		// assign a value to the uniform (be done after actavation)
	m_texture->bind();				// bind texture so it's appears
	m_VAO->bind();					// bind the VAO so OpenGL Knows to use it
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		// Draw the triangle using the GL_TRIANGLES primitive
}
