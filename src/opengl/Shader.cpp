

#include "Shader.h"

#include <string>
#include <fstream>      // std::ifstream
#include <sstream>
#include <iostream>
#include <cerrno>
#include <GLFW/glfw3.h>


std::string get_file_contents(const char* filename)
{

	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);


}



Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Read files	 and store strings
	std::string vertexCode		= get_file_contents(vertexFile);
	std::string fragmentCode	= get_file_contents(fragmentFile);

	// convert shader source strings into char
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();



	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);		// Create vertex shader	and get reference
	glShaderSource(vertexShader, 1, &vertexSource, NULL);		// Attach vertex shader source to the object
	glCompileShader(vertexShader);								// compile the shader into machine code
	compileErrors(vertexShader, "VERTEX");

	GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);		// Create fragment shader and get reference
	glShaderSource(FragmentShader, 1, &fragmentSource, NULL);		// Attach fragment shader source to the object
	glCompileShader(FragmentShader);								// compile the shader into machine code
	compileErrors(FragmentShader, "FRAGMENT");

	this->m_ID = glCreateProgram();					// Create vertex shader	and get reference
	glAttachShader(this->m_ID, vertexShader);	// Attach vertex shader source to the shader program
	glAttachShader(this->m_ID, FragmentShader);	// Attach fragment shader source to the shader program
	glLinkProgram(this->m_ID);					// Wrap/link all the shaders together into the shader program
	compileErrors(this->m_ID, "PROGRAM");

	glDeleteShader(vertexShader);	// Delete useless Vertex shader		
	glDeleteShader(FragmentShader);	// Delete useless fragment shader	

}

void Shader::activate()
{
	glUseProgram(this->m_ID);	// tell OpenGL wich shader program we want to use 
}

void Shader::terminate()
{
	glDeleteProgram(m_ID);
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog); 
			std::cout << "SHADER_COMPILATION_ERROR for : " << type << "\n" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for : " << type << "\n" << std::endl;
		}
	}
}
