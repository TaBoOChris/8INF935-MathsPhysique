#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"
#include "Shader.h"

class Texture
{
public:
	GLuint m_ID;
	const char* m_type;

	Texture(const char* image, const char* texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);

	void bind();		// bind a texture
	void unBind();		// unbind a texture
	void terminate();	// deletes a texture	




};

