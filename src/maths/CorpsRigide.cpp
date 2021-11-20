#include "CorpsRigide.h"

CorpsRigide::CorpsRigide() {
	float inverseMass = 1.0f;
	float linearDamping = 0.0f;
	Vector3D position;
	Vector3D velocite;
	Vector3D acceleration;
	Vector3D rotation;			//velicte angulaire
	Quaternion orientation;
	float angularDamping = 0.0f;
	Matrix3 transformMatrix;
	Matrix3 inverseInertiaTensor;

}

CorpsRigide::CorpsRigide(float inverseMasse) {
	float inverseMass = inverseMasse;
	float linearDamping = (inverseMasse == 0) ? -1.0f : 1/inverseMasse;
	Vector3D position;
	Vector3D velocite;
	Vector3D acceleration;
	Vector3D rotation;			//velicte angulaire
	Quaternion orientation;
	float angularDamping;
	Matrix3 transformMatrix;
	Matrix3 inverseInertiaTensor;
}
CorpsRigide::CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration) {
	float inverseMass = 1.0f;
	float linearDamping = 0.0f;
	Vector3D position = initialPosition;
	Vector3D velocite = initialVitesse;
	Vector3D acceleration = initialAcceleration;
	Vector3D rotation;			//velicte angulaire
	Quaternion orientation;
	float angularDamping = 0.0f;
	Matrix3 transformMatrix;
	Matrix3 inverseInertiaTensor;
}

void CorpsRigide::calculDonneesDerivee() {

}