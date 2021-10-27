#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Model.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class UserInterface
{

private:

	ImGuiIO io;


public:

	UserInterface(GLFWwindow* window);

	void frameCreation();
	void frameOption(std::vector<Model*> models, float time);

	void terminate();
};

