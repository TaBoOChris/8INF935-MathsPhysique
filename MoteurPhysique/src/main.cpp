#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include "Mesh.h"
#include "Model.h"
#include "CubeMesh.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "Particule.h"



#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(void)
{
	Vector3D u(1, 4, 5);
	Vector3D v(2);

	cout << u.normalisation();

	//------------------------------

	MoteurPhysique my_MoteurPhysique;
	GLFWwindow* window = my_MoteurPhysique.initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

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

	Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(0.0f, 1.0f, 4.0f));

	// IMGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;	// keep cursor hide when we move camera

	//---


	double prevTime = 0.0f;
	double crntTime = 0.0f;
	double timeDiff;
	unsigned int counter = 0;

	//glfwSwapInterval(60);


	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string modelPath = "/ressources/Blob/scene.gltf";

	std::cout << parentDir + modelPath << std::endl;

	Model model((parentDir + modelPath).c_str());

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

		}


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		if (!io.WantCaptureMouse) {
			io.MouseClicked[ImGuiMouseButton_Right] = GLFW_MOUSE_BUTTON_RIGHT;
		}

		// camera 
		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);
		


		// draw model
		model.Draw(shaderProgram, camera);
		
		//ImGui Frame option

		ImGui::Begin("I'm Window, ImGui Window");
		ImGui::Text("Let's play with particle");
		if (ImGui::Button("Balle")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			
		}
		ImGui::SameLine();
		if (ImGui::Button("Boulets")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			
		}
		ImGui::SameLine();
		if (ImGui::Button("Laser")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			
		}
		ImGui::SameLine();
		if (ImGui::Button("Boule de feu")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			
		}

		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// moteur 
		my_MoteurPhysique.display();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	shaderProgram.terminate();

	my_MoteurPhysique.terminate();

	return 0;
}


/*
int main(void)
{
    Vector3D u(1, 4, 5);
    Vector3D v(2);

    cout << u.normalisation();

    //------------------------------

    MoteurPhysique my_MoteurPhysique; 
    GLFWwindow* window = my_MoteurPhysique.initWindow(800, 800);
    

	std::vector<Mesh> meshes;
	// Create floor mesh
	Mesh floor;	
	floor.bind();
	meshes.push_back(floor);

	std::vector<CubeMesh> allCubes;


	//----


	glEnable(GL_DEPTH_TEST);

    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT,glm::vec3(0.0f,1.0f,4.0f));

	// IMGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;	// keep cursor hide when we move camera

	//---


	double prevTime = 0.0f;
	double crntTime = 0.0f;
	double timeDiff;
	unsigned int counter = 0;

	//glfwSwapInterval(60);

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
			
		}


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		if (!io.WantCaptureMouse) {
			io.MouseClicked[ImGuiMouseButton_Right] = GLFW_MOUSE_BUTTON_RIGHT;
		}

		// camera 
        camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// meshes
		for (Mesh mesh : meshes) {
			mesh.Draw(camera , 1.0f);
		}

		// cubes
		for (CubeMesh cube : allCubes) {
			cube.update(glfwGetTime());
			cube.Draw(camera,0.05f);
		}


		//ImGui Frame option

		ImGui::Begin("I'm Window, ImGui Window");
		ImGui::Text("Let's play with particle");
		if (ImGui::Button("Balle")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			CubeMesh newCube((float)glfwGetTime());
			newCube.m_particule->setInverseMasse(0.5f);
			newCube.m_particule->setVitesse(Vector3D(0.05f, 0.0f, 0.0f));
			newCube.bind();
			allCubes.push_back(newCube);
		}
		ImGui::SameLine();
		if (ImGui::Button("Boulets")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			CubeMesh newCube((float)glfwGetTime());
			newCube.m_particule->setInverseMasse(0.8f);
			newCube.m_particule->setVitesse(Vector3D(0.1f, 0.1f, 0.0f));
			newCube.bind();
			allCubes.push_back(newCube);
		}
		ImGui::SameLine();
		if (ImGui::Button("Laser")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			CubeMesh newCube((float)glfwGetTime());
			newCube.m_particule->setInverseMasse(0.01f);
			newCube.m_particule->setVitesse(Vector3D(0.1f, 0.0f, 0.0f));
			newCube.bind();
			allCubes.push_back(newCube);
		}
		ImGui::SameLine();
		if (ImGui::Button("Boule de feu")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			CubeMesh newCube((float)glfwGetTime());
			newCube.m_particule->setInverseMasse(0.6f);
			newCube.m_particule->setVitesse(Vector3D(0.2f, 0.02f, 0.0f));
			newCube.bind();
			allCubes.push_back(newCube);
		}
			
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// moteur 
        my_MoteurPhysique.display();
    }

	// terminate mesh (shader)
	for (Mesh mesh : meshes) {
		mesh.terminate();
	}

	for (CubeMesh cube : allCubes) {
		cube.terminate();
	}
	
	ImGui_ImplOpenGL3_Shutdown(); 
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

    my_MoteurPhysique.terminate();

    return 0;
}

*/