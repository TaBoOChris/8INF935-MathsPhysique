#pragma once

#include "../Vecteur3D.h"

class Contact
{
private:
	Vector3D contactPoint;			// Point de contact
	Vector3D contactNormal;			// Normal du contact
	float penetration;				// penetration
		
public:

	// ------ Constructor ----------
	Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration);

	// ------ Print  ----------
	friend ostream& operator<<(ostream& os, Contact const& contact);
};

