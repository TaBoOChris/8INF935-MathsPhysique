#pragma once
/// <summary>
/// L'objet doit tourner autour du centre de mass
/// 
/// </summary>


#include "Vecteur3D.h"
#include "Quaternion.h"
#include "Matrix3.h"

class CorpsRigide
{
private:
	float inverseMass;
	float linearDamping;
	Vector3D position;
	Vector3D velocite;
	Vector3D acceleration;
	Quaternion orientation;
	Vector3D rotation;			//velicte angulaire

	Matrix3 transformMatrix;

	Matrix3 inverseInertiaTensor;

	float angularDamping;
	

public:

	CorpsRigide();

	CorpsRigide(float inverseMasse);

	CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration);

	void calculDonneesDerivee();

	void forceAccum();
	void torqueAccum();
	void clearAccumulators();

	void addForceAtPoint(Vector3D force, Vector3D point);
	void addForceAtBodyPoint(Vector3D force, Vector3D point);

	
};

