#pragma once
#include "../Vecteur3D.h"
#include "VolumeEnglobant.h"

class OcTree {
public:
	Vector3D firstPoint;
	Vector3D secondPoint;
	float sideLen;


	/*
	* L'ocTree est construit avec ses enfants de la facon suivante :
	*		   E--F
	*		  /  /|
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

	//Volumes englobant []



};