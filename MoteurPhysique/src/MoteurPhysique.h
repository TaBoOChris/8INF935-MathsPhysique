#pragma once
class MoteurPhysique
{
private:
	class GLFWwindow* m_window;


public : 

	GLFWwindow* initWindow(int windowWidth, int windowHeight);
	void display();
	void terminate();

	void drawRectangle();
	void drawTriangle();

	void drawLines();
	void test();

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};

