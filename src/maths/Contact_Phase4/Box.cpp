#include "Box.h"

Box::Box()
{
}

Box::Box(CorpsRigide* self, Vector3D halfsizes, Matrix4 matrix)
{
	this->Body = self;
	this->halfsizes = halfsizes;
	this->offset = matrix;
	updateMesh();
}

Vector3D Box::getHalfsize()
{
	return this->halfsizes;
}

Matrix4 Box::getOffset()
{
	return this->offset;
}

CorpsRigide* Box::getBody()
{
	return this->Body;
}

void Box::setPoints(std::vector<Vector3D*> vect)
{
	points = vect;
}

void Box::setMesh()
{
	// Vertices coordinates
	Vertex vertices[] =
	{ //               COORDINATES                                   /            COLORS          /           TexCoord         /       NORMALS         //
		Vertex{glm::vec3(points[0]->x, points[0]->y,  points[0]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(points[1]->x, points[1]->y,  points[1]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(points[2]->x, points[2]->y,  points[2]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(points[3]->x, points[3]->y,  points[3]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(points[4]->x, points[4]->y,  points[4]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(points[5]->x, points[5]->y,  points[5]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(points[6]->x, points[6]->y,  points[6]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(points[7]->x, points[7]->y,  points[7]->z),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
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

void Box::Draw(Shader& shader, Camera& camera)
{

	setMesh();					// On cree notre objet
	mesh.Draw(shader, camera);	// On l'affiche

}

void Box::updateMesh() {

	Quaternion orientation = Body->getOrientation(); // On recup l'orientation

	// On definit les 8 points de notre cube
	std::vector<Vector3D*> eightpoints;
	eightpoints.push_back(new Vector3D(0.0f, 0.0f, 0.0f));
	eightpoints.push_back(new Vector3D(this->getHalfsize().x, 0.0f, 0.0f));
	eightpoints.push_back(new Vector3D(this->getHalfsize().x, this->getHalfsize().y, 0.0f));
	eightpoints.push_back(new Vector3D(0.0f, this->getHalfsize().y, 0.0f));
	eightpoints.push_back(new Vector3D(0.0f, 0.0f, this->getHalfsize().z));
	eightpoints.push_back(new Vector3D(this->getHalfsize().x, 0.0f, this->getHalfsize().z));
	eightpoints.push_back(new Vector3D(this->getHalfsize().x, this->getHalfsize().y, this->getHalfsize().z));
	eightpoints.push_back(new Vector3D(0.0f, this->getHalfsize().y, this->getHalfsize().z));

	// Pour chaque points, on applique la rotation
	for (Vector3D* vec : eightpoints)
	{
		*vec = *vec * this->getOffset();
		*vec = vec->rotateByQuaternion(orientation);
		*vec = *vec + this->getBody()->getPosition();
	}
	this->setPoints(eightpoints);
}
