#pragma once

#include<string>
#include <iostream>
#include <vector>
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Mesh
{
public :
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	std::vector <Texture> textures;
	// Store VAO in public so it can be used in the Draw function
	VAO VAO;


	// store shader program
	Shader* shaderProgram; // ("default.vert", "default.frag");

	// Initializes the mesh
	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures);

	// Draws the mesh
	void Draw(Camera& camera, float posX, float posY, float posZ);

	void terminate();
};

