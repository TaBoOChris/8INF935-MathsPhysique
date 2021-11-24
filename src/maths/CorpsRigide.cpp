#include "CorpsRigide.h"

CorpsRigide::CorpsRigide() {
	this->inverseMass = 1.0f;
	this->linearDamping = 0.0f;
	this->position;
	this->velocite;
	this->acceleration;
	this->rotation;			//velicte angulaire
	this->orientation_0 = Quaternion(0, 0, 0, 1);
	this->orientation = orientation_0;
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
	this->angularDamping = 0.0f;
	this->transformMatrix;
	this->calculDonneesDerivee();
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
	this->transformMatrix = this->transformMatrix.setOrientation(this->orientation);
}

void CorpsRigide::addForce(Vector3D force)
{
	this->m_forceAccum = this->m_forceAccum + force;
}

void CorpsRigide::addTorque(Vector3D torque)
{
	this->m_torqueAccum = this->m_torqueAccum + torque;
}

void CorpsRigide::clearAccumulators()
{
	this->m_forceAccum = Vector3D();
	this->m_torqueAccum = Vector3D();
}

void CorpsRigide::addForceAtPoint(Vector3D force, Vector3D point)
{

	this->m_forceAccum	= m_torqueAccum		+	force;
	this->m_torqueAccum = m_torqueAccum		+	(point - this->position).produitvectoriel( force);
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

void CorpsRigide::setInverseInertiaTensor(Matrix3 inverseInertia) {
	this->inverseInertiaTensor = inverseInertia;
}

void CorpsRigide::integrer(float temps) {
	this->updateLinearAcceleration(temps);		// calcul l'acceleration lineaire a partir de Force Accum
	this->updateAngularAcceleration(temps);		// calcul l'acceleration angulaire a partir de force Accum
	this->updateLinearVelocity(temps);			// On update la velocite lineaire
	this->updateAngularVelocity(temps);			// On update la velocite angulaire
	//TODO this->drag();
	this->updatePosition(temps);				// On update la position
	this->updateOrientation(temps);				// On update l'orientation
	this->calculDonneesDerivee();				// On calcul la matrice de transformation
	this->clearAccumulators();					// On vide les accumulators
	//std::cout << "torque : "<<this->m_forceAccum;
}

void CorpsRigide::updateLinearAcceleration(float temps) {
	this->acceleration = this->inverseMass * this->m_forceAccum;
}

void CorpsRigide::updateAngularAcceleration(float temps) {
	this->accelerationAngulaire = this->inverseInertiaTensor * this->m_torqueAccum;
}

void CorpsRigide::updateLinearVelocity(float temps) {
	this->velocite = this->velocite + this->acceleration * temps;
}

void CorpsRigide::updateAngularVelocity(float temps) {
	this->rotation = this->rotation + this->accelerationAngulaire * temps;
}

void CorpsRigide::updatePosition(float temps) {
	this->position = this->position + this->velocite * temps + this->acceleration * pow(temps, 2) * 0.5f;
}

void CorpsRigide::updateOrientation(float temps) {
	Quaternion velocityAngular = Quaternion(this->rotation.x, this->rotation.y, this->rotation.z, 0.0f);
	
	this->orientation = this->orientation_0 + (temps/2.f) * (velocityAngular * this->orientation_0);
	//this->orientation.normalize();
}

Quaternion CorpsRigide::getOrientation() {
	return this->orientation;
}

Vector3D CorpsRigide::getPosition() {
	return this->position;
}