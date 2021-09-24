#pragma once
#include "Vecteur3D.h"

class Particule
{
private :

	float inverseMasse;
	float frottement;

	Vector3D position;
	Vector3D vitesse;
	Vector3D acceleration;

public :

	Vector3D appliedForce;

	float getInverseMasse();

	void updateAcceleration();

	void updateVitesse(float temps);

	void updatePosition(float temps);

	void integrer(float temps);


};

