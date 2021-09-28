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
#include "Vecteur3D.h"

class Mesh
{

protected:

	Vector3D position;

public :

	void test() { std::cout << "parent : \n" << position << std::endl; }

	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	std::vector <Texture> textures;
	// Store VAO in public so it can be used in the Draw function
	VAO VAO;


	// store shader program
	Shader* shaderProgram; // ("default.vert", "default.frag");

	Mesh();

	// Initializes the mesh
	void bind();

	// Draws the mesh
	void Draw(Camera& camera, float scale);

	void terminate();
};

