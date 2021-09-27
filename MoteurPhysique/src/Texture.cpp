#include "Texture.h"

Texture::Texture(const char* image, GLenum textType, GLenum slot, GLenum format, GLenum pixelType)
{
	m_type = textType;	// Assigns the type of the texture to the texture object

	int widthImg, heightImg, numColCh;		// gets the width, the height, and number of color chanels
	stbi_set_flip_vertically_on_load(true);	// flip the image to show it in the right side
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);	// read and store image in bytes 

	glGenTextures(1, &m_ID);		// Gen an OpenGL texture obj
	glActiveTexture(slot);			// Assigns the texture to a texture unit
	glBindTexture(textType, m_ID);

	// configure the type of algo to make the image smaller/ bigger
	glTexParameteri(textType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	
	glTexParameteri(textType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// configure the way the texture repeat
	glTexParameteri(textType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(textType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// extra line for GL_CLAMP_TO_BORDER
	//float flatColor[] = { 1.0f, 1.0f,1.0f,1.0f };
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	
	glTexImage2D(textType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);	// Assigns image to the openGL Texture obj 
	glGenerateMipmap(textType);	// gen MipMaps

	stbi_image_free(bytes);			// delete image data as it is already in the texture object
	glBindTexture(textType, 0);		// unbind opengl texture , it can't accidentally be modified
}

void Texture::texUnit(Shader shader, const char* uniform, GLuint unit)
{
	GLuint textUni = glGetUniformLocation(shader.m_ID, uniform);
	shader.activate();
	glUniform1i(textUni, unit);
}

void Texture::bind()
{
	glBindTexture(m_type, m_ID);

}

void Texture::unBind()
{
	glBindTexture(m_type, 0);

}

void Texture::terminate()
{
	glDeleteTextures(1, &m_ID);

}
