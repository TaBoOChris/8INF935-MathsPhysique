#include "UserInterface.h"

UserInterface::UserInterface(GLFWwindow* window)
{
	// IMGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	this->io = ImGui::GetIO(); (void)this->io;

	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;	// keep cursor hide when we move camera
}

void UserInterface::frameCreation()
{
	// ImGUI Frame Creation
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	if (!io.WantCaptureMouse) {
		io.MouseClicked[ImGuiMouseButton_Right] = GLFW_MOUSE_BUTTON_RIGHT;
	}

}

void UserInterface::frameOptionForModel(std::vector<Model*> models, float time)
{

	ImGui::Begin("I'm Window, ImGui Window");
	ImGui::Text("Let's play with particle");
	ImGui::Text("Time = %.3f",time);

	/*
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
	*/

	int index = 1;
	for (Model *myModel : models)
	{

		ImGui::Text("Particule %i  position    (x : %.2f  y : %.2f  z:%.2f ) ", index,
			myModel->getParticule()->getPosition().x, 
			myModel->getParticule()->getPosition().y,
			myModel->getParticule()->getPosition().z);


		ImGui::Text("Particule %i  vitesse     (x : %.2f  y : %.2f  z:%.2f ) ", index,
			myModel->getParticule()->getVitesse().x,
			myModel->getParticule()->getVitesse().y,
			myModel->getParticule()->getVitesse().z);

		ImGui::Text("Particule %i  acc         (x : %.2f  y : %.2f  z:%.2f ) ", index,
			myModel->getParticule()->getAcceleration().x,
			myModel->getParticule()->getAcceleration().y,
			myModel->getParticule()->getAcceleration().z);


		ImGui::Text("Particule %i  accumForce  (x : %.2f  y : %.2f  z:%.2f )", index,
			myModel->getParticule()->accumForce.x,
			myModel->getParticule()->accumForce.y,
			myModel->getParticule()->accumForce.z);

		ImGui::NewLine();

		index++;
	}
	if (models.size() >= 2) {
		float distance = (models[0]->getPosition() - models[1]->getPosition()).norme();
		ImGui::Text("Distance entre les particules 0 et 1 : % f", distance);
	}

	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::frameOptionForRigidBody(FormeIrreguliere forme, float time)
{
	ImGui::Begin("8INF935 - Mathematiques et physique ");
	ImGui::Text("Phase 3 : Gestion des corps rigides ");

	ImGui::NewLine();
	ImGui::Text("Time = %.3f", time);
	
	//Affichage des 8 points 
	ImGui::NewLine();
	int index = 0;
	for (Vector3D *pt : forme.allPointsMonde) {
		ImGui::Text("pt %i  position    (x : %.2f  y : %.2f  z:%.2f ) ", index,
			pt->x,
			pt->y,
			pt->z);

		index++;
	}


	// Affichage de la TransformMatrix
	Matrix4 mat = forme.selfCorps->getTransformMatrix();

	ImGui::NewLine();
	ImGui::Text("TransformMatrix");
	ImGui::Text("%.2f %.2f %.2f %.2f  \n%.2f %.2f %.2f %.2f  \n%.2f %.2f %.2f %.2f",
		mat.a00, mat.a01, mat.a02, mat.a03,
		mat.a10, mat.a11, mat.a12, mat.a13,
		mat.a20, mat.a21, mat.a22, mat.a23);




	//----
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::terminate()
{

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
