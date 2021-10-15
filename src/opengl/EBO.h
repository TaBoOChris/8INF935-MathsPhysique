#pragma once

#include <glad/glad.h>


#include <vector>


class EBO
{

public:
	GLuint m_ID;

	EBO(std::vector<GLuint>& indices);

	void bind();		// Bind the EBO
	void unBind();		// unBind the EBO
	void terminate();	// delete the EBO
};
