#include "ObjectToDraw.h"


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

void ObjectToDraw::initialization()
{

	// Vertices Coordinates
	GLfloat vertices[] = {
		-0.5f, 0.5f,
		 0.5f, -0.5f,
		 0.0f,	 0.5f
	};

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(FragmentShader);

	this->m_shaderProgram = glCreateProgram();

	glAttachShader(this->m_shaderProgram, vertexShader);
	glAttachShader(this->m_shaderProgram, FragmentShader);
	glLinkProgram(this->m_shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(FragmentShader);

	
	glGenVertexArrays(1, &this->m_VAO);
	glGenBuffers(1, &this->m_VBO);
	
	glBindVertexArray(this->m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



}

void ObjectToDraw::terminate()
{
	glDeleteVertexArrays(1, &this->m_VAO);
	glDeleteBuffers(1, &this->m_VBO);
	glDeleteProgram(m_shaderProgram);
}

void ObjectToDraw::display()
{
	glUseProgram(this->m_shaderProgram);
	glBindVertexArray(this->m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
