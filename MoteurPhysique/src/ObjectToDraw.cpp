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


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};


// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

ObjectToDraw::ObjectToDraw()
{


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


	// time
	m_prevTime = glfwGetTime();
	m_rotation = 0.0f;

	glEnable(GL_DEPTH_TEST);
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

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shaderProgram->activate();	// Telle OpenGL wich shader we want to use

	//---


	double crntTime = glfwGetTime();
	if (crntTime - m_prevTime >= 1 / 30) {
		m_rotation += 0.05f;
		m_prevTime = crntTime; 
	}

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	model = glm::rotate(model, glm::radians(m_rotation), glm::vec3(1.0f, 1.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
	proj = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.0f);

	int modelLoc = glGetUniformLocation(m_shaderProgram->m_ID,"model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	
	int viewLoc = glGetUniformLocation(m_shaderProgram->m_ID,"view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	
	int projLoc = glGetUniformLocation(m_shaderProgram->m_ID,"proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
	
	
	
	//----
	glUniform1f(m_uniID, 0.5f);		// assign a value to the uniform (be done after actavation)
	m_texture->bind();				// bind texture so it's appears
	m_VAO->bind();					// bind the VAO so OpenGL Knows to use it
	glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);		// Draw the triangle using the GL_TRIANGLES primitive
}
