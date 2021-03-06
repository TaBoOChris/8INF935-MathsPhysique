#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.h"


class Camera
{
public :
	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	bool firstClick = true;

	int width;
	int height;

	float defaultSpeed =	0.05f;
	float maxSpeed = defaultSpeed * 4.0f;
	float speed = defaultSpeed;
	float sensitivity = 100.0f;

	Camera(int width, int height, glm::vec3 position);

	// Updates the camera matrix to the Vertex Shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

	void Matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);

};

