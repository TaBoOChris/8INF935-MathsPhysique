#pragma once

#include "../Vecteur3D.h"

class Contact
{

public:
	Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration);

private:

	Vector3D contactPoint;
	Vector3D contactNormal;
	float penetration;
		

};

