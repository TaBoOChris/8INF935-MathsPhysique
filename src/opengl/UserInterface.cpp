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

void UserInterface::frameOption(Vector3D blobPosition)
{

	ImGui::Begin("I'm Window, ImGui Window");
	ImGui::Text("Let's play with particle");
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
	ImGui::Text("x : %.2f  y : %.2f  z:%.2f", blobPosition.x, blobPosition.y, blobPosition.z);

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
