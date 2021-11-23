#pragma once

#include "Vecteur3D.h"
#include "CorpsRigide.h"
#include <vector>


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


	FormeIrreguliere();

	void updateAllPoint(float temps);

	void Draw();
};

