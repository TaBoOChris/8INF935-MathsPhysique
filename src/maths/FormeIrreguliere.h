#pragma once
#include <vector>

#include "../opengl/Mesh.h"
#include "../opengl/Texture.h"

#include "Vecteur3D.h"
#include "CorpsRigide.h"


class FormeIrreguliere
{
public :

	CorpsRigide* selfCorps;

	std::vector<Vector3D*> allPoints;

	Vector3D pt0;
	Vector3D pt1;
	Vector3D pt2;
	Vector3D pt3;
	Vector3D pt4;
	Vector3D pt5;
	Vector3D pt6;
	Vector3D pt7;

	Mesh mesh;

	FormeIrreguliere();

	void updateAllPoint(float temps);

	void setMesh();
	void Draw(Shader& shader, Camera& camera);

};

