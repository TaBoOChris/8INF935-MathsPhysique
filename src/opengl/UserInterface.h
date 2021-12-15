#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Model.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "../maths/FormeIrreguliere.h"
#include "../maths/Contact_Phase4/CollisionData.h"
#include "../maths/Contact_Phase4/Box.h"


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
	void frameOptionForModel(std::vector<Model*> models, float time);


	void frameOptionForRigidBody(FormeIrreguliere forme, float time);

	void frameOptionForPh4(
		CollisionData collisionData,
		CorpsRigide rb,
		Box box,
		float time);

	void terminate();
};

