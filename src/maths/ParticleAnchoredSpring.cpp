#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3D anchor, float constElast, float lenRepos)
{
	this->anchor = anchor;
	this->K = constElast;
	this->l0 = lenRepos;
}

ParticleAnchoredSpring::~ParticleAnchoredSpring()
{
}

void ParticleAnchoredSpring::updateForce(Particule* particule)
{
	float longueur = (particule->getPosition() - anchor).norme();
	Vector3D force = K * (l0 - longueur);
	particule->addForce(force);
}
