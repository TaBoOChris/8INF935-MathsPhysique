#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>	
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

#include "maths/Vecteur3D.h"
#include "maths/Particule.h"
#include "maths/Matrix3.h"
#include "maths/Matrix4.h"
#include "maths/Quaternion.h"
#include "maths/CorpsRigide.h"
#include "maths/FormeIrreguliere.h"

#include "maths/force/RegistreForces.h"
#include "maths/force/BungeeString.h"
#include "maths/force/DragGenerator.h"
#include "maths/force/GravityGenerator.h"
#include "maths/force/ParticleAnchoredSpring.h"
#include "maths/force/ParticleBuoyancy.h"
#include "maths/force/ParticleSpring.h"

#include "maths/FormeIrreguliere.h"

#include "opengl/Model.h"
#include "opengl/UserInterface.h"
#include "opengl/MoteurPhysique.h"



#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

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

	Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(30.0f, 10.0f, 0.0f));

	UserInterface my_UI(window);

	//---

	double prevTime = 0.0f;
	double crntTime = 0.0f;
	double timeDiff;
	unsigned int counter = 0;

	//glfwSwapInterval(60);

	//----------------------------------------------------------------------------------------------------------
	

	// Model Creation
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string floorPath = "/8INF935-MathsPhysique/ressources/floor/floor.gltf";

	// floor creation
	Model floor((parentDir + floorPath).c_str());


	FormeIrreguliere forme = FormeIrreguliere();
	

	// Boucle de Rendu
	while (!glfwWindowShouldClose(window))
	{
		// handle 60fps
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

			forme.updateAllPoint(timeDiff);

			//----
			// Gestion des inputs
			camera.Inputs(window);
		}

		// Specify the color of the background
		glClearColor(0.85f, 0.85f, 0.90f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		//my_UI.frameCreation();

		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);



		// draw floor
		floor.Draw(shaderProgram, camera);

		
		forme.Draw(shaderProgram, camera);
		
		// moteur 
		my_MoteurPhysique.display();
	}
	
	my_UI.terminate();
	shaderProgram.terminate();
	my_MoteurPhysique.terminate();
	return 0;
	
}

