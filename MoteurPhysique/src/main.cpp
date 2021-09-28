#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include "Mesh.h"
#include "CubeMesh.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "Particule.h"


using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800



int main(void)
{
    Vector3D u(1, 4, 5);
    Vector3D v(2);

    cout << u.normalisation();

    //------------------------------

    MoteurPhysique my_MoteurPhysique; 

    GLFWwindow* window = my_MoteurPhysique.initWindow(800, 800);
    
    

	// Create floor mesh
	Mesh floor;	


	floor.bind();


	std::vector<Mesh> meshes;
	meshes.push_back(floor);

	std::vector<CubeMesh> allCubes;

	//----

	



	glEnable(GL_DEPTH_TEST);

    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT,glm::vec3(2.0f,2.0f,2.0f));

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

	Particule my_particule(Vector3D(0.0f,50.0f,0.0f) , Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, -0.1f, 0.0f));
	std::cout << my_particule.getPosition() << std::endl;

	//-
	float position = 0.0f;
	double prevTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ImGUI Frame Creation
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		if (!io.WantCaptureMouse) {
			io.MouseClicked[ImGuiMouseButton_Right] = GLFW_MOUSE_BUTTON_RIGHT;
		}

		// Time boucle
		double crntTime = glfwGetTime();
		if (crntTime-prevTime >= 1)
		{	
			std::cout << "t = " << glfwGetTime() << std::endl;
			my_particule.integrer(glfwGetTime());
			std::cout << my_particule.getPosition() << std::endl;


			position += 0.000005f;
			prevTime = crntTime;
		}

		// camera 
        camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// meshes
		for (Mesh mesh : meshes) {
			mesh.Draw(camera , 0.0f, 0.0f, 0.0f ,1.0f);
		}

		// cubes
		for (CubeMesh cube : allCubes) {
			
			cube.Draw(camera, 0.0f, 1.0f, 0.0f, 0.1f); 
		}


		//ImGui Frame option

		ImGui::Begin("I'm Window, ImGui Window");
		ImGui::Text("Let's play with particle");
		if (ImGui::Button("Balle")) {			// Buttons return true when clicked (most widgets return true when edited/activated)
			CubeMesh newCube;
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

