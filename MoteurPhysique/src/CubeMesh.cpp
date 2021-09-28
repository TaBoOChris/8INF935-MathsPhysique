#include "CubeMesh.h"

CubeMesh::CubeMesh()
{

	Vertex vertices_tmp[] =
	{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // 0 gauche devant	bas
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)}, // 1 gauche derrière bas
		Vertex{glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)}, // 2 droite derrière bas
		Vertex{glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}, // 3 droite devant	bas
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // 4 gauche devant	haut
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)}, // 5 gauche derrière haut
		Vertex{glm::vec3( 1.0f,  1.0f, -1.0f),  glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)}, // 6 droite derrière haut
		Vertex{glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}, // 7 droite devant	haut
	};

	// Indices for vertices order
	GLuint indices_tmp[] =
	{
		0, 1, 2,
		0, 2, 3,
		1, 0, 4,
		1, 5, 4,
		1, 2, 5,
		5, 2, 6,
		2, 3, 6,
		6, 3, 7,
		0, 3, 7,
		7, 4, 0,
		4, 5, 6,
		4, 6, 7,
	};

	// Texture data
	Texture textures_tmp[]
	{
		Texture("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices_tmp, vertices_tmp + sizeof(vertices_tmp) / sizeof(Vertex));
	std::vector <GLuint> ind(indices_tmp, indices_tmp + sizeof(indices_tmp) / sizeof(GLuint));
	std::vector <Texture> tex(textures_tmp, textures_tmp + sizeof(textures_tmp) / sizeof(Texture));


	Mesh::vertices = verts;
	Mesh::indices = ind;
	Mesh::textures = tex;


}
