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

#include "maths/Contact_Phase4/Box.h"
#include "maths/Contact_Phase4/BVH.h"
#include "maths/Contact_Phase4/CollisionData.h"
#include "maths/Contact_Phase4/Contact.h"
#include "maths/Contact_Phase4/Plane.h"
#include "maths/Contact_Phase4/Primitive.h"
#include "maths/Contact_Phase4/SphereEnglobante.h"

#include "opengl/Model.h"
#include "opengl/UserInterface.h"
#include "opengl/MoteurPhysique.h"
#include "opengl/VAO.h"
#include "opengl/EBO.h"
#include "opengl/Camera.h"
#include "opengl/Texture.h"




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

	glEnable(GL_DEPTH_TEST);
	

	// floor creation
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string floorPath = "/8INF935-MathsPhysique/ressources/floor/floor.gltf";
	std::string boxPath = "/8INF935-MathsPhysique/ressources/box/box.gltf";
	Model floor((parentDir + floorPath).c_str());
	Model boxMesh((parentDir + boxPath).c_str());

	// Def de CorpsRigide de la box
	CorpsRigide* bodyBox = new CorpsRigide(Vector3D(0.0f, 10.0f, 0.0f), Vector3D(0.0f), Vector3D(0.0f));
	Matrix3* inertiaTensor = new Matrix3(
		8.0f / 12.0f, 0.0f, 0.0f,
		0.0f, 8.0f / 12.0f, 0.0f,
		0.0f, 0.0f, 8.0f / 12.0f
	);
	bodyBox->setInverseInertiaTensor(inertiaTensor->getInverse());
	
	// Def de la box
	Box* box = new Box(bodyBox, Vector3D(1.0f), Matrix4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f));

	// Def Plan
	Plane* plane = new Plane(Vector3D(0.0f, 0.0f, 1.0f), 19.0f);

	// Def du BVH
	BVH* bvh = new BVH(bodyBox->getSphereEnglobante());

	// Def CollisionData
	CollisionData* cd = new CollisionData();
	
	// Def de la forme irreguliere
	/*FormeIrreguliere *forme = new FormeIrreguliere();
	forme->selfCorps->setVelocite(Vector3D(0, 6.f, -5.5f));
	forme->selfCorps->setRotation(Vector3D(45.f, 0, 0));*/


	// Def de l'UI
	UserInterface my_UI(window);

	// Def de la camera
	Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(30.0f, 10.0f, 0.0f));


	//Init Time
	double prevTime = 0.0f;
	double crntTime = 0.0f;
	double timeDiff;
	unsigned int counter = 0;
	
	bool playSimu = true;
	// Boucle de Rendu
	while (!glfwWindowShouldClose(window))
	{
		// handle 60fps
		crntTime = glfwGetTime();
		timeDiff = crntTime - prevTime;
		counter++;
		if (timeDiff >= 1.0 / 30.0) {
			// ------ fps and ms calcul ------
			std::string FPS = std::to_string((1.0 / timeDiff) * counter);
			std::string ms = std::to_string((timeDiff / counter) * 1000);
			std::string newTitle = "MoteurPhysique ( " + FPS + "fps, " + ms + "ms)";
			glfwSetWindowTitle(window, newTitle.c_str());
			prevTime = crntTime;
			counter = 0;

			if (playSimu) {
				// ------ Forme Irregu ---------
				bodyBox->addForce(Vector3D(0, -9.81f * pow(10, -1), -3.0f));
				bodyBox->setRotation(Vector3D(1.0f, 0.0f, 0.0f));
				//forme->selfCorps->addForceAtPoint(Vector3D(0.0f, 2.0f, 0.0f), Vector3D(0, 0, 1));
				bodyBox->integrer(timeDiff);
				box->updateMesh();
			}
			
			
			camera.Inputs(window);	// Gestion des inputs

			
		}

		// Specify the color of the background
		glClearColor(0.85f, 0.85f, 0.90f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		my_UI.frameCreation();								// ImGUI Frame Creation
		camera.updateMatrix(45.0f, 0.1f, 100.0f);			// Updates and exports the camera matrix to the Vertex Shader
		floor.Draw(shaderProgram, camera);					// draw floor
		boxMesh.Draw(shaderProgram, camera);
		box->Draw(shaderProgram, camera);					// draw forme


		
		cd->generateContact(box, plane);

		if (playSimu == true)
			cd->printContact_console();
		
		my_UI.frameOptionForPh4(*cd, *bodyBox , *box, crntTime );	// affichage des infos de l'UI
		my_MoteurPhysique.display();						// affichage du moteur a l'ecran

		if (cd->getContacts().size() > 0) { playSimu = false; }
	}
	
	my_UI.terminate();					// Mettre fin a l'UI
	shaderProgram.terminate();			// Mettre fin aux shader
	my_MoteurPhysique.terminate();		// Mettre fin au moteur
	return 0;
	
}

