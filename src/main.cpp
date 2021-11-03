#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>	
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

#include "maths/Vecteur3D.h"
#include "maths/Particule.h"
#include "maths/force/RegistreForces.h"

#include "maths/force/BungeeString.h"
#include "maths/force/DragGenerator.h"
#include "maths/force/GravityGenerator.h"
#include "maths/force/ParticleAnchoredSpring.h"
#include "maths/force/ParticleBuoyancy.h"
#include "maths/force/ParticleSpring.h"

#include "maths/contact/ParticleContactResolver.h"
#include "maths/contact/ParticleLink.h"
#include "maths/contact/ParticleRod.h"
#include "maths/contact/ParticleCable.h"

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
	
	// Contact --------------
	std::vector<ParticleContactGenerator*> particleContactGens;

	// Model Creation
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string modelPath = "/8INF935-MathsPhysique/ressources/Blob/blob.gltf";
	std::string floorPath = "/8INF935-MathsPhysique/ressources/floor/floor.gltf";

	//création du vecteur de models
	std::vector<Model*> models;

	RegistreForces registre;					// On cree les forces

	int nombre_particules = 2;
	for (size_t i = 0; i < nombre_particules; i++)
	{
		// Model and particule creation
		Model* newModel = new Model((parentDir + modelPath).c_str());
		newModel->getParticule()->setPosition(  Vector3D(0.0f,5, -(nombre_particules/2.0f) + i*2.0f )   );
		models.push_back(newModel);

		//////////////// Création des Forces ////////////////
		
		// Gravity force creation
		registre.add(
			models[i]->getParticule(), 
			new GravityGenerator(Vector3D (0,-9.81 * pow(10,-5) , 0))
		);

		//Drag generator
		registre.add(
			models[i]->getParticule(),
			new DragGenerator( 0.05f, 0.05f)
		);
		
		// Simple elastic on lie les particules avec la particule centrale (1/2)
		/*if (i > 0)
			registre.add(
				models[i]->getParticule(),
				new ParticleSpring(models[0]->getParticule(),0.05f,2.5f, 4.0f)
			);
		*/

		// AnchoredSpring
		/*Vector3D vec = models[i]->getPosition();
		vec.y += 1;
		registre.add(
			models[i]->getParticule(),
			new ParticleAnchoredSpring(vec, 0.01f, 2)
		);*/

		// Elastic de Bungee
		/*if(i > 0)
			registre.add(
				models[i]->getParticule(),
				new BungeeString(models[0]->getParticule(),0.01f,6)
			);*/

		// Buoyancy
		/*registre.add(
			models[i]->getParticule(),
			new ParticleBuoyancy(-3.0f, models[i]->getParticule()->getRayon() * 4.0f * 3.14f * 3.14f, 0.0f, 1.1f)
		);*/

		//////////////// Création des ParticleLink ////////////////

		// Rod
		/*for (Model* loadModel : models) {
			ParticleRod* rod = new ParticleRod(newModel->getParticule(), loadModel->getParticule(), 6.0f);
			particleContactGens.push_back(rod);
		}*/
		// Cable
		/*for (Model* loadModel : models) {
			ParticleCable* cable = new ParticleCable(newModel->getParticule(), loadModel->getParticule(), 6.0f, 0.5f);
			particleContactGens.push_back(cable);
		}*/
	}
	// Simple elastic On met un elastic entre toutes les particules (2/2)
	/*for (size_t i = 1; i < nombre_particules; i++) {
		for (size_t j = 1; j < nombre_particules; j++) {
			if (i != j) {
				registre.add(
					models[i]->getParticule(),
					new ParticleSpring(models[j]->getParticule(), 0.05f, 2.5f)
				);
			}
		}
	}*/

	// floor creation
	Model floor((parentDir + floorPath).c_str());

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

			//----
			// Gestion des inputs
			camera.Inputs(window);
			models[0]->Inputs(window);
		}

		// Specify the color of the background
		glClearColor(0.85f, 0.85f, 0.90f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		my_UI.frameCreation();

		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Apply force of the registre
		registre.updateAllForces(timeDiff);

		for (Model* my_model : models)
		{
			my_model->updateParticule(timeDiff);
			my_model->updatePosition();
		}

		//////////////// Gestion des contacts ////////////////
		std::vector<ParticleContact*> particleContacts;

		// Ajoute un contact entre les particules qui sont entrées en collision
		for (Model* modelA : models) {
			for (Model* modelB : models)
			{
				Vector3D modelA_pos = modelA->getPosition();
				if (modelA != modelB) {
					Vector3D modelB_pos = modelB->getPosition();
					float distance = (modelA_pos - modelB_pos).norme();
					if (distance < modelA->getParticule()->getRayon() + modelB->getParticule()->getRayon()) {
						// Crée un particuleContact si la distance entre deux particules est inférieure à la somme de leurs rayons
						ParticleContact* tmp;
						tmp = new ParticleContact(modelA->getParticule(), modelB->getParticule(), 1.0f);
						tmp->setPenetration(modelA->getParticule()->getRayon() + modelB->getParticule()->getRayon() - distance);
						particleContacts.push_back(tmp);
					}
				}
				else {
					break;
				}
			}
		}

		// Ajoute un contact pour les particules liees avec un lien
		for (ParticleContactGenerator* my_gen : particleContactGens) {
			my_gen->ajouterContact(particleContacts);
		}

		// Resoud tous les contacts dans le vecteur avec ParticuleContactResolver
		ParticleContactResolver particleContactResolver;
		particleContactResolver.resolveContact(particleContacts, timeDiff);

		// Dessine les particules
		for (Model* my_model : models) {
			// draw model
			my_model->Draw(shaderProgram, camera);			
		}

		// draw floor
		floor.Draw(shaderProgram, camera);
		
		my_UI.frameOption(models,crntTime); //ImGui Frame option

		// moteur 
		my_MoteurPhysique.display();
	}
	
	my_UI.terminate();
	shaderProgram.terminate();
	my_MoteurPhysique.terminate();
	return 0;
	
}

