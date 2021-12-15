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
	
	//Affichage des 8 points world
	ImGui::NewLine();
	int index = 0;
	for (Vector3D *pt : forme.allPointsMonde) {
		ImGui::Text("pt %i  Worldposition    (x : %.2f  y : %.2f  z:%.2f ) ", index,
			pt->x,
			pt->y,
			pt->z);

		index++;
	}
	float cote = sqrt((forme.allPointsMonde[0]->x - forme.allPointsMonde[1]->x) * (forme.allPointsMonde[0]->x - forme.allPointsMonde[1]->x) + (forme.allPointsMonde[0]->y - forme.allPointsMonde[1]->y) * (forme.allPointsMonde[0]->y - forme.allPointsMonde[1]->y));

	//ImGui::Text("Taille d'un coté : %.2f", cote);

	//Affichage des 8 points  obj
	ImGui::NewLine();
	index = 0;
	for (Vector3D pt : forme.allPointsObjet) {
		ImGui::Text("pt %i Objectposition    (x : %.2f  y : %.2f  z:%.2f ) ", index,
			pt.x,
			pt.y,
			pt.z);

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


	// Affichage de l'orientation
	Quaternion orientation = forme.selfCorps->getOrientation();

	ImGui::NewLine();
	ImGui::Text("Orientation");
	ImGui::Text("x:%.2f    y:%.2f    z:%.2f     w:%.2f ",
		orientation.x ,  orientation.y , orientation.z , orientation.w);


	// Affichage de force et troque accum
	ImGui::NewLine();
	/*
	ImGui::Text("forceAccum : x:%.2f    y:%.2f    z:%.2f ",
		forme.selfCorps->getForceAccum().x, forme.selfCorps->getForceAccum().y, forme.selfCorps->getForceAccum().z);

	ImGui::Text("TorqueAccum : x:%.2f    y:%.2f    z:%.2f",
		forme.selfCorps->getTorqueAccum().x, forme.selfCorps->getTorqueAccum().y, forme.selfCorps->getTorqueAccum().z);

	ImGui::Text("Acceleration Angulaire : x:%.2f    y:%.2f    z:%.2f",
		forme.selfCorps->getAccelerationAngulaire().x, forme.selfCorps->getAccelerationAngulaire().y, forme.selfCorps->getAccelerationAngulaire().z);
	*/

	ImGui::Text("Rotation: x:%.2f    y:%.2f    z:%.2f",
		forme.selfCorps->getRotation().x, forme.selfCorps->getRotation().y, forme.selfCorps->getRotation().z);


	if (ImGui::Button("reset pos")) {			// Button for reset Position intial speed
		forme.selfCorps->setPosition(Vector3D(0, 0, 0));
		forme.selfCorps->setVelocite(Vector3D(0, 10.f, -3.5f));
		forme.selfCorps->setRotation(Vector3D(45.f, 0, 0));
	}
	//----
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::frameOptionForPh4(CollisionData collisionData, CorpsRigide rb, Box box, float time)
{
	ImGui::Begin("8INF935 - Mathematiques et physique ");
	ImGui::Text("Phase 4 : Systeme Elementaire de Resolution de Collisions ");

	ImGui::NewLine();
	ImGui::Text("Time = %.3f", time);

	ImGui::NewLine();
	ImGui::Text("---------------------------------");
	ImGui::NewLine();
	ImGui::Text("Collision Data");
	ImGui::Text("Nombre contact = " , collisionData.getContacts().size());


	ImGui::NewLine();
	ImGui::Text("---------------------------------");
	ImGui::NewLine();

	ImGui::Text("CorpsRigide");

	// Affichage de la TransformMatrix
	Matrix4 mat = rb.getTransformMatrix();

	ImGui::NewLine();
	ImGui::Text("TransformMatrix");
	ImGui::Text("%.2f %.2f %.2f %.2f  \n%.2f %.2f %.2f %.2f  \n%.2f %.2f %.2f %.2f",
		mat.a00, mat.a01, mat.a02, mat.a03,
		mat.a10, mat.a11, mat.a12, mat.a13,
		mat.a20, mat.a21, mat.a22, mat.a23);


	// Affichage de l'orientation
	Quaternion orientation = rb.getOrientation();

	ImGui::NewLine();
	ImGui::Text("Orientation");
	ImGui::Text("x:%.2f    y:%.2f    z:%.2f     w:%.2f ",
		orientation.x, orientation.y, orientation.z, orientation.w);



	ImGui::NewLine();
	ImGui::Text("---------------------------------");
	ImGui::NewLine();

	ImGui::Text("Box");


	int index = 0;
	for (Vector3D* pt : box.getPoints())
	{
		ImGui::Text("pt %i Objectposition    (x : %.2f  y : %.2f  z:%.2f ) ", index,
			pt->x,
			pt->y,
			pt->z);

		index++;
	}


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
