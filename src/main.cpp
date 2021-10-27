#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>	
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

#include "maths/Vecteur3D.h"
#include "maths/Particule.h"
#include "maths/RegistreForces.h"

#include "opengl/Model.h"
#include "opengl/UserInterface.h"
#include "opengl/MoteurPhysique.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(void)
{

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	MoteurPhysique my_MoteurPhysique;
	GLFWwindow* window = my_MoteurPhysique.initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);


	// Generates Shader object using shaders default.vert and default.frag

	Shader shaderProgram("src/opengl/default.vert", "src/opengl/default.frag");

	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	shaderProgram.activate();
	glUniform4f(glGetUniformLocation(shaderProgram.m_ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.m_ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	//----

	glEnable(GL_DEPTH_TEST);

	Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));

	UserInterface my_UI(window);

	//---

	double prevTime = 0.0f;
	double crntTime = 0.0f;
	double timeDiff;
	unsigned int counter = 0;

	//glfwSwapInterval(60);

	// Model Creation
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string modelPath = "/8INF935-MathsPhysique/ressources/Blob/blob.gltf";
	std::string floorPath = "/8INF935-MathsPhysique/ressources/floor/floor.gltf";

	std::vector<Model> models;
	
	for (size_t i = 0; i < 4; i++)
	{
		models.push_back(Model((parentDir + modelPath).c_str()));
	}
	
	Model floor((parentDir + floorPath).c_str());

	// Main While
	while (!glfwWindowShouldClose(window))
	{

		crntTime = glfwGetTime();
		timeDiff = crntTime - prevTime;
		counter++;
		if (timeDiff >= 1.0 / 30.0) {
			// fps and ms calcul
			std::string FPS = std::to_string((1.0 / timeDiff) * counter);
			std::string ms = std::to_string((timeDiff / counter) * 1000);
			std::string newTitle = "MoteurPhysique ( " + FPS + "fps, " + ms + "ms)";
			glfwSetWindowTitle(window, newTitle.c_str());
			prevTime = crntTime;
			counter = 0;

			//----
			// mange input
			camera.Inputs(window);
			models[0].Inputs(window);
		}

		// Specify the color of the background
		glClearColor(0.85f, 0.85f, 0.90f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		my_UI.frameCreation();

		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		for (Model my_model : models)
		{
			my_model.updateParticule(timeDiff);

			// draw model
			my_model.Draw(shaderProgram, camera);
		}

		// draw floor
		floor.Draw(shaderProgram, camera);
		
		my_UI.frameOption(models[0].getPosition()); //ImGui Frame option

		// moteur 
		my_MoteurPhysique.display();
	}
	
	my_UI.terminate();
	shaderProgram.terminate();
	my_MoteurPhysique.terminate();
	return 0;
	
}

