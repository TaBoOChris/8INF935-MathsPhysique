#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Texture.h"
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"

class ObjectToDraw
{

private :


	float m_rotation = 0.0f;
	double m_prevTime;

	VAO* m_VAO;
	VBO* m_VBO;
	EBO* m_EBO;

	GLuint m_uniID;
	Texture* m_texture;

public :

	ObjectToDraw(); // constructor

	void initialization(Shader& shader);

	void terminate();

	void display();

};

