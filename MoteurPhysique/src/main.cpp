#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include"Mesh.h"
#include "CubeMesh.h"
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
	Mesh floor2;

	CubeMesh cube;

	cube.bind();

	floor.bind();
	floor2.bind();


	std::vector<Mesh> meshes;
	meshes.push_back(floor);
	meshes.push_back(floor2);
	//----

	



	glEnable(GL_DEPTH_TEST);

    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT,glm::vec3(2.0f,2.0f,2.0f));


	float position = 0.0f;
	double prevTime = glfwGetTime();
	float i = 1;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Time boucle
		double crntTime = glfwGetTime();
		if (crntTime-prevTime >= 1/30)
		{
			position += 0.000005f;
			prevTime = crntTime;
		}

		// camera 
        camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// meshes
		for (Mesh mesh : meshes) {
			mesh.Draw(camera , 0.0f, i*  position, 0.0f ,1.0f);
			i = -i;
		}

		cube.Draw(camera, 0.0f, 1.0f, 0.0f, 0.1f); 

		// moteur 
        my_MoteurPhysique.display();
    }

	// terminate mesh (shader)
	for (Mesh mesh : meshes) {
		mesh.terminate();
	}

	cube.terminate();
    my_MoteurPhysique.terminate();

    return 0;
}

