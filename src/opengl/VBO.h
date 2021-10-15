#pragma once

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

// Vertex Buffer Object 
class VBO
{

public:
	GLuint m_ID;	// ref ID of the VBO

	VBO(std::vector<Vertex>& vertices);	// COnstructor 

	void bind();		// Bind the VBO
	void unBind();		// unBind the VBO
	void terminate();	// delete the vbo
};

