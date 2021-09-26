#pragma once
class MoteurPhysique
{
private:
	class GLFWwindow* m_window;


public : 

	int initWindow();
	void display();

	void drawRectangle();
	void drawTriangle();

	void drawLines();
	void test();

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};

