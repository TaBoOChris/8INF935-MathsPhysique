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
	this->sphereEnglobante.center = this->position;
	this->sphereEnglobante.rayon = 1.0f;
}

CorpsRigide::CorpsRigide(float inverseMasse) {
	this->inverseMass = inverseMasse;
	this->linearDamping = (inverseMasse == 0) ? -1.0f : 1/inverseMasse;
	this->position;
	this->velocite;
	this->acceleration;
	this->rotation;			//velicte angulaire
	this->orientation_0 = Quaternion(0, 0, 0, 1);
	this->orientation = orientation_0;
	this->angularDamping = 0.0f;
	this->transformMatrix;
	this->calculDonneesDerivee();
	this->inverseInertiaTensor;
	this->sphereEnglobante.center = this->position;
	this->sphereEnglobante.rayon = 1.0f;
}

CorpsRigide::CorpsRigide(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration) {
	this->inverseMass = 1.0f;
	this->linearDamping = 0.0f;
	this->position = initialPosition;
	this->velocite = initialVitesse;
	this->acceleration = initialAcceleration;
	this->rotation;			//velicte angulaire
	this->orientation_0 = Quaternion(0, 0, 0, 1);
	this->orientation = orientation_0;
	this->angularDamping = 0.0f;
	this->transformMatrix;
	this->inverseInertiaTensor;
	this->sphereEnglobante.center = this->position;
	this->sphereEnglobante.rayon = 1.0f;
}

// definir l'orientation de transformMatrix 
void CorpsRigide::calculDonneesDerivee() {
	this->transformMatrix = this->transformMatrix.setOrientation(this->orientation);
}

// add force in ForceAccum
void CorpsRigide::addForce(Vector3D force)
{
	this->m_forceAccum = this->m_forceAccum + force;	
}

// add Torque in TorqueAccum
void CorpsRigide::addTorque(Vector3D torque)
{
	this->m_torqueAccum = this->m_torqueAccum + torque;
}

// Set ForceAccum et TorqueAccum a 0
void CorpsRigide::clearAccumulators()
{
	this->m_forceAccum = Vector3D();
	this->m_torqueAccum = Vector3D();
}

// ajouter une force a un point precis de l'obj
void CorpsRigide::addForceAtPoint(Vector3D force, Vector3D point)
{
	this->m_forceAccum	= this->m_forceAccum + m_torqueAccum + force;
	this->m_torqueAccum = m_torqueAccum		+	(point - this->position).produitvectoriel( force);
}

// ajouter une force a un point precis de l'obj dans le repere local
void CorpsRigide::addForceAtBodyPoint(Vector3D force, Vector3D point)
{
	Vector3D worldSpacePoint = this->GetPointInWorldSpace(this->position);
	this->addForceAtPoint(force, worldSpacePoint);
}

// retourne le point dans le repere local
Vector3D CorpsRigide::GetPointInLocalSpace(const Vector3D point)
{
	return this->transformMatrix.transformInversePosition(point);
}

// retourne le point dans le repere global
Vector3D CorpsRigide::GetPointInWorldSpace(const Vector3D point)
{
	return this->transformMatrix.transformPosition(point);
}

SphereEnglobante_t CorpsRigide::getSphereEnglobante()
{
	return this->sphereEnglobante;
}

// Integrateur
void CorpsRigide::integrer(float temps) {
	this->updateLinearAcceleration(temps);		// calcul l'acceleration lineaire a partir de Force Accum
	this->updateAngularAcceleration(temps);		// calcul l'acceleration angulaire a partir de Troque Accum
	this->updateLinearVelocity(temps);			// On update la velocite lineaire
	this->updateAngularVelocity(temps);			// On update la velocite angulaire
	//TODO this->drag();
	this->updatePosition(temps);				// On update la position
	this->updateOrientation(temps);				// On update l'orientation
	this->calculDonneesDerivee();				// On calcul la matrice de transformation
	this->clearAccumulators();					// On vide les accumulators
}

// inverse mass * les force accumule
void CorpsRigide::updateLinearAcceleration(float temps) {
	this->acceleration = this->inverseMass * this->m_forceAccum;	
}

// inverseInertiaTensor * les torque accumule
void CorpsRigide::updateAngularAcceleration(float temps) {
	this->accelerationAngulaire = this->inverseInertiaTensor * this->m_torqueAccum;		
}

// On ajoute l'acceleration à la velocite
void CorpsRigide::updateLinearVelocity(float temps) {
	this->velocite = this->velocite + this->acceleration * temps;		
}

// On ajoute l'acceleration Angular à la rotation
void CorpsRigide::updateAngularVelocity(float temps) {
	this->rotation = this->rotation + this->accelerationAngulaire * temps;		
}

// applique l'acc et la velocite a la position 
void CorpsRigide::updatePosition(float temps) {
	
	this->position = this->position + this->velocite * temps + this->acceleration * pow(temps, 2) * 0.5f;
	this->sphereEnglobante.center = this->position;
}

// calcul de la vitesse angulaire pour obtenir l'orientation
void CorpsRigide::updateOrientation(float temps) {

	Quaternion velocityAngular = Quaternion(this->rotation.x, this->rotation.y, this->rotation.z, 0.0f);
	
	this->orientation = this->orientation + (temps/2.f) * (velocityAngular * this->orientation);
	this->orientation.normalize();
}

