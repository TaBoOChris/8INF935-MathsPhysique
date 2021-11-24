#pragma once
#include <vector>

#include "../opengl/Mesh.h"
#include "../opengl/Texture.h"

#include "Vecteur3D.h"
#include "CorpsRigide.h"


class FormeIrreguliere
{
public :

	std::vector<Vector3D> allPointsObjet;
	std::vector<Vector3D*> allPointsMonde;

	CorpsRigide* selfCorps;

	Mesh mesh;

	FormeIrreguliere();

	void updateAllPoint(float temps);				// Update la position de chaque point dans le repere globale

	void setPointsObjetCoord();						// definir la position des points dans le repere local
	void setMesh();									// construire le Mesh
	void Draw(Shader& shader, Camera& camera);		// Afficher le mesh
};

