#include "FormeIrreguliere.h"

FormeIrreguliere::FormeIrreguliere()
{

	setPointsObjetCoord();			// On defini les points dans le repere local

	for (size_t i = 0; i < 8; i++)
	{
		allPointsMonde.push_back(new Vector3D());	// On creer les point du repere global
	}

	selfCorps = new CorpsRigide();					// On creer le corps rigide

	// On defini notre matrice d'inertie
	Matrix3* inertiaTensor = new Matrix3(
		8.0f / 12.0f, 0.0f, 0.0f,
		0.0f, 8.0f / 12.0f, 0.0f,
		0.0f, 0.0f, 8.0f / 12.0f
	);

	selfCorps->setInverseInertiaTensor(inertiaTensor->getInverse());		// On ajoute la matrice au corps rigide
}

void FormeIrreguliere::updateAllPoint(float temps) {
	
	setPointsObjetCoord();	// On defini les points dans le repere local


	Quaternion orientation = this->selfCorps->getOrientation();	// on recupere l'orientation du RigidBody


	// Pour chaque point, on calcul les position dans le repere monde
	int index = 0;
	for (Vector3D* pt : allPointsMonde){
		*pt = allPointsObjet[index].rotateByQuaternion(orientation);	
		*pt = *pt + this->selfCorps->getPosition();
		index++;
	}
}



void FormeIrreguliere::setMesh()
{
	// Vertices coordinates
	Vertex vertices[] =
	{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
		Vertex{glm::vec3(allPointsMonde[0]->x, allPointsMonde[0]->y,  allPointsMonde[0]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(allPointsMonde[1]->x, allPointsMonde[1]->y,  allPointsMonde[1]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[2]->x, allPointsMonde[2]->y,  allPointsMonde[2]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[3]->x, allPointsMonde[3]->y,  allPointsMonde[3]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[4]->x, allPointsMonde[4]->y,  allPointsMonde[4]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[5]->x, allPointsMonde[5]->y,  allPointsMonde[5]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[6]->x, allPointsMonde[6]->y,  allPointsMonde[6]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(allPointsMonde[7]->x, allPointsMonde[7]->y,  allPointsMonde[7]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		//Left
		0, 1, 2,
		0, 2, 3,

		//Bottom
		0, 3, 4,
		3, 4, 7,

		//Right
		5, 7, 4,
		5, 7, 6,

		//top
		1, 2, 5,
		2, 5, 6,

		//Front
		2, 3, 7,
		2, 7, 6,

		//Back
		0, 1, 4,
		1, 4, 5

	};

	// Texture data
	Texture textures[]
	{
			Texture("white.png", "diffuse", 0),
	};


	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	mesh = Mesh(verts, ind, tex);
}

void FormeIrreguliere::Draw(Shader& shader, Camera& camera)
{
	
	setMesh();					// On cree notre objet
	mesh.Draw(shader, camera);	// On l'affiche

}

void FormeIrreguliere::setPointsObjetCoord()
{
	allPointsObjet.clear();			// On supprime les anciens points

	// On cree les 8 points du cube
	Vector3D pt0 = Vector3D(-1, -1, -1);
	allPointsObjet.push_back(pt0);
	Vector3D pt1 = Vector3D(-1, -1, 1);
	allPointsObjet.push_back(pt1);
	Vector3D pt2 = Vector3D(-1, 1, 1);
	allPointsObjet.push_back(pt2);
	Vector3D pt3 = Vector3D(-1, 1, -1);
	allPointsObjet.push_back(pt3);
	Vector3D pt4 = Vector3D(1, -1, -1);
	allPointsObjet.push_back(pt4);
	Vector3D pt5 = Vector3D(1, -1, 1);
	allPointsObjet.push_back(pt5);
	Vector3D pt6 = Vector3D(1, 1, 1);
	allPointsObjet.push_back(pt6);
	Vector3D pt7 = Vector3D(1, 1, -1);
	allPointsObjet.push_back(pt7);
}
