#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include"Mesh.h"

using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// Vertices coordinates
Vertex vertices[] =
{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};



int main(void)
{
    Vector3D u(1, 4, 5);
    Vector3D v(2);

    cout << u.normalisation();

    //------------------------------

    MoteurPhysique my_MoteurPhysique; 

    GLFWwindow* window = my_MoteurPhysique.initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    

	// Texture data
	Texture textures[]
	{
		Texture("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE) 
	};


	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts, ind, tex);	
	Mesh floor2(verts, ind, tex);


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
			mesh.Draw(camera , 0.0f, i*  position, 0.0f);
			i = -i;
		}

		// moteur 
        my_MoteurPhysique.display();
    }

	// terminate mesh (shader)
	for (Mesh mesh : meshes) {
		mesh.terminate();
	}
    my_MoteurPhysique.terminate();

    return 0;
}

