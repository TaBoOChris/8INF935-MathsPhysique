#include "CorpsRigide.h"

CorpsRigide::CorpsRigide() {
	this->inverseMass = 1.0f;
	this->linearDamping = 0.0f;
	this->position;
	this->velocite;
	this->acceleration;
	this->rotation;			//velicte angulaire
	this->orientation;
	this->angularDamping = 0.0f;
	this->transformMatrix;
	this->inverseInertiaTensor;

}

CorpsRigide::CorpsRigide(float inverseMasse) {
	this->inverseMass = inverseMasse;
	this->linearDamping = (inverseMasse == 0) ? -1.0f : 1/inverseMasse;
	this->position;
	this->velocite;
	this->acceleration;
	this->rotation;			//velicte angulaire
	this->orientation;
	this->angularDamping;
	this->transformMatrix;
	this->inverseInertiaTensor;
}
CorpsRigide::CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration) {
	this->inverseMass = 1.0f;
	this->linearDamping = 0.0f;
	this->position = initialPosition;
	this->velocite = initialVitesse;
	this->acceleration = initialAcceleration;
	this->rotation;			//velicte angulaire
	this->orientation;
	this->angularDamping = 0.0f;
	this->transformMatrix;
	this->inverseInertiaTensor;
}

void CorpsRigide::calculDonneesDerivee() {

}