#pragma once

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

	// Constructeurs ------------------
	CorpsRigide();
	CorpsRigide(float inverseMasse);
	CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration);

	// getter ------------------
	Vector3D getPosition() { return this->position; }
	Quaternion getOrientation() { return orientation; }
	Matrix4 getTransformMatrix() { return transformMatrix; }
	Vector3D getForceAccum() { return m_forceAccum; }
	Vector3D getTorqueAccum() { return m_torqueAccum; }
	Vector3D getAccelerationAngulaire() { return this->accelerationAngulaire; }
	Vector3D getRotation() { return this->rotation; }

	// setter ------------------
	void setPosition(Vector3D n_position) { this->position = n_position; }
	void setVelocite(Vector3D n_velocite) { this->velocite = n_velocite; }
	void setRotation(Vector3D n_rotation) { this->rotation = n_rotation; }
	void setInverseInertiaTensor(Matrix3 inverseInertia){ this->inverseInertiaTensor = inverseInertia; }

	

	// Methodes principales ------------------
	void calculDonneesDerivee();		// definir l'orientation de transformMatrix 
	void addForce(Vector3D force);		// add force in ForceAccum
	void addTorque(Vector3D torque);	// add Torque in TorqueAccum
	void clearAccumulators();			// Set ForceAccum et TorqueAccum a 0

	void addForceAtPoint(Vector3D force, Vector3D point);		// ajouter une force a un point precis de l'obj
	void addForceAtBodyPoint(Vector3D force, Vector3D point);	// ajouter une force a un point precis de l'obj dans le repere local


	Vector3D GetPointInLocalSpace(const Vector3D point);		// retourne le point dans le repere local
	Vector3D GetPointInWorldSpace(const Vector3D point);		// retourne le point dans le repere global
	
	void integrer(float temps);						// Integrateur
	void updateLinearAcceleration(float temps);		// inverse mass * les force accumule
	void updateAngularAcceleration(float temps);	// inverseInertiaTensor * les torque accumule
	void updateLinearVelocity(float temps);			// On ajoute l'acceleration à la velocite
	void updateAngularVelocity(float temps);		// On ajoute l'acceleration Angular à la rotation
	void updatePosition(float temps);				// applique l'acc et la velocite a la position 
	void updateOrientation(float temps);			// calcul de la vitesse angulaire pour obtenir l'orientation

};

