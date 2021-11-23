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

	std::vector<Vector3D> allPointsObjet;

	std::vector<Vector3D*> allPointsMonde;

	Mesh mesh;

	FormeIrreguliere();

	void updateAllPoint(float temps);

	void setMesh();
	void Draw(Shader& shader, Camera& camera);

	void setPointsObjetCoord();

};

