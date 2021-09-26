#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"

class ObjectToDraw
{

private :

	//GLfloat *m_vertices;
	VAO* m_VAO;
	VBO* m_VBO;
	EBO* m_EBO;
	Shader* m_shaderProgram;

	GLuint m_uniID;

public :

	ObjectToDraw(); // constructor

	void initialization();

	void terminate();

	void display();

};

