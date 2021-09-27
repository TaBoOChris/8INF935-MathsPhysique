#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class MoteurPhysique
{
private:
	GLFWwindow* m_window;

public : 

	GLFWwindow* initWindow(int windowWidth, int windowHeight);
	void display();
	void terminate();

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);


};

