#pragma once
#include "../Vecteur3D.h"
#include "SphereEnglobante.h"
#include <vector>

class OcTree {

private:
	std::vector<SphereEnglobante*> objectsInside;

public:
	Vector3D firstPoint;
	Vector3D secondPoint;
	float sideLen;


	/*
	* L'ocTree est construit avec ses enfants de la facon suivante :
	*		   E--F
	*		  /| /|
	*		 H--G |
	*		 | A|-B
	*   y  	 |/ |/
	*   |-x	 D--C
	*  /
	* z  
	* 
	*
	*/

	OcTree* childA = nullptr;
	OcTree* childB = nullptr;
	OcTree* childC = nullptr;
	OcTree* childD = nullptr;
	OcTree* childE = nullptr;
	OcTree* childF = nullptr;
	OcTree* childG = nullptr;
	OcTree* childH = nullptr;

	OcTree();
	std::vector<SphereEnglobante*> getObjectsInside();
	int getNumberInside();
	void addObjectInside(SphereEnglobante* new_object);
};