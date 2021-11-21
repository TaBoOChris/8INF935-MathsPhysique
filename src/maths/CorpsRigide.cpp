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
	this->transformMatrix = Matrix3();
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
	float x = orientation.x;
	float y = orientation.y;
	float z = orientation.z;
	float w = orientation.w;
	this->transformMatrix = Matrix3(
		1.0f - 2.0f * (x * x + y * y), 2.0f * (x * y + z * w), 2.0f * (x * z - y * w),
		2.0f * (x * y - z * w), 1.0f - 2.0f * (x * x + z * z), 2.0f * (y * z + x * w),
		2.0f * (x * z + y * w), 2.0f * (y * z - x * w), 1.0f - 2.0f * (x * x + y * y)
	);
}

void CorpsRigide::addForce(Vector3D force)
{
	this->m_forceAccum = this->m_forceAccum + force;
}

void CorpsRigide::addTorque(Vector3D torque)
{
	this->m_torqueAccum = this->m_torqueAccum + torque;
}

void CorpsRigide::addForceAtPoint(Vector3D force, Vector3D point)
{

	this->m_forceAccum	= m_torqueAccum		+	force;
	this->m_torqueAccum = m_torqueAccum		+	(point - this->position) * force;
}

void CorpsRigide::addForceAtBodyPoint(Vector3D force, Vector3D point)
{
	// Convert to coordinates relative to center of mass.
	Vector3D worldSpacePoint = this->GetPointInWorldSpace(this->position);
	this->addForceAtPoint(force, worldSpacePoint);
}

Vector3D CorpsRigide::GetPointInLocalSpace(const Vector3D point)
{
	return this->transformMatrix.transformInversePosition(point);

}

Vector3D CorpsRigide::GetPointInWorldSpace(const Vector3D point)
{
	return this->transformMatrix.transformPosition(point);
}
