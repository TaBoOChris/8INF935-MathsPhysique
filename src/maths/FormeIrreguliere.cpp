#include "FormeIrreguliere.h"

FormeIrreguliere::FormeIrreguliere()
{
	pt0 = Vector3D(-1, -1, -1);
	allPoints.push_back(&pt0);
	pt1 = Vector3D(-1, -1, 1);
	allPoints.push_back(&pt1);
	pt2 = Vector3D(-1, 1, 1);
	allPoints.push_back(&pt2);
	pt3 = Vector3D(-1, 1, -1);
	allPoints.push_back(&pt3);
	pt4 = Vector3D(1, -1, -1);
	allPoints.push_back(&pt4);
	pt5 = Vector3D(1, -1, 1);
	allPoints.push_back(&pt5);
	pt6 = Vector3D(1, 1, 1);
	allPoints.push_back(&pt6);
	pt7 = Vector3D(1, 1, -1);
	allPoints.push_back(&pt7);

	selfCorps = new CorpsRigide();

	Matrix3* inertiaTensor = new Matrix3(
		8.0f / 12.0f, 0.0f, 0.0f,
		0.0f, 8.0f / 12.0f, 0.0f,
		0.0f, 0.0f, 8.0f / 12.0f
	);

	selfCorps->setInverseInertiaTensor(inertiaTensor->getInverse());
}

void FormeIrreguliere::updateAllPoint(float temps) {
	Quaternion orientation = this->selfCorps->getOrientation();

	for (Vector3D* pt : allPoints) {
		pt->rotateByQuaternion(orientation);
	}
}



void FormeIrreguliere::setMesh()
{
	// Vertices coordinates
	Vertex vertices[] =
	{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
		Vertex{glm::vec3(pt0.x, pt0.y,  pt0.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(pt1.x, pt1.y,  pt1.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(pt2.x, pt2.y,  pt2.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(pt3.x, pt3.y,  pt3.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(pt4.x, pt4.y,  pt4.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(pt5.x, pt5.y,  pt5.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(pt6.x, pt6.y,  pt6.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(pt7.x, pt7.y,  pt7.z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
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
	/*mesh.vertices[0].position = glm::vec3(pt0.x, pt0.y, pt0.z);
	mesh.vertices[1].position = glm::vec3(pt1.x, pt1.y, pt1.z);
	mesh.vertices[2].position = glm::vec3(pt2.x, pt2.y, pt2.z);
	mesh.vertices[3].position = glm::vec3(pt3.x, pt3.y, pt3.z);
	mesh.vertices[4].position = glm::vec3(pt4.x, pt4.y, pt4.z);
	mesh.vertices[5].position = glm::vec3(pt5.x, pt5.y, pt5.z);
	mesh.vertices[6].position = glm::vec3(pt6.x, pt6.y, pt6.z);
	mesh.vertices[7].position = glm::vec3(pt7.x, pt7.y, pt7.z);*/


	setMesh();
	mesh.Draw(shader, camera);

}