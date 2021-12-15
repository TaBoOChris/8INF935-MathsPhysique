#pragma once

#include "../Vecteur3D.h"

class Contact
{

public:
	Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration);



	friend ostream& operator<<(ostream& os, Contact const& contact);


private:

	Vector3D contactPoint;
	Vector3D contactNormal;
	float penetration;




		

};

