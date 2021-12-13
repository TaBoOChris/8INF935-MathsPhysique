#pragma once
#include "../Vecteur3D.h"
#include "../CorpsRigide.h"


// Bounding Sphere 
class SphereEnglobante {
public:
	Vector3D position;

	float rayon;

	CorpsRigide self;

};