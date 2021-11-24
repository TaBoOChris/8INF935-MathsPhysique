#pragma once
/// <summary>
/// L'objet doit tourner autour du centre de mass
/// 
/// </summary>


#include "Vecteur3D.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"

class CorpsRigide
{
private:
	float inverseMass;
	float linearDamping;
	Vector3D position;
	Vector3D velocite;
	Vector3D acceleration;
	Quaternion orientation;
	Quaternion orientation_0;
	Vector3D accelerationAngulaire;
	Vector3D rotation;			//velicte angulaire

	Matrix4 transformMatrix;

	Matrix3 inverseInertiaTensor;

	float angularDamping;

	// ------------- Force -------------

	Vector3D m_forceAccum;
	Vector3D m_torqueAccum;
	

public:

	CorpsRigide();

	CorpsRigide(float inverseMasse);

	CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration);


	Matrix4 getTransformMatrix() { return transformMatrix; }
	Vector3D getForceAccum() { return m_forceAccum; }
	Vector3D getTorqueAccum() { return m_torqueAccum; }
	Vector3D getAccelerationAngulaire() { return this->accelerationAngulaire; }
	Vector3D getRotation() { return this->rotation; }

	void calculDonneesDerivee();

	void addForce(Vector3D force);
	void addTorque(Vector3D torque);
	void clearAccumulators();

	void addForceAtPoint(Vector3D force, Vector3D point);
	void addForceAtBodyPoint(Vector3D force, Vector3D point);

	void setInverseInertiaTensor(Matrix3 inverseInertia);

	Vector3D GetPointInLocalSpace(const Vector3D point);

	Vector3D GetPointInWorldSpace(const Vector3D point);
	
	void integrer(float temps);
	void updateLinearAcceleration(float temps);
	void updateAngularAcceleration(float temps);
	void updateLinearVelocity(float temps);
	void updateAngularVelocity(float temps);
	void updatePosition(float temps);
	void updateOrientation(float temps);

	Vector3D getPosition();

	Quaternion getOrientation();
};

