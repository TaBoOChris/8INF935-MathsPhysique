#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ObjectToDraw
{

private :

	//GLfloat m_vertices[];
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_shaderProgram;

public :

	void initialization();

	void terminate();

	void display();

};

