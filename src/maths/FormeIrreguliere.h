#pragma once

#include "Vecteur3D.h"
#include "../opengl/Mesh.h"
#include "../opengl/Texture.h"

class FormeIrreguliere
{
public :

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

	void setMesh();
	void Draw(Shader& shader, Camera& camera);
};

