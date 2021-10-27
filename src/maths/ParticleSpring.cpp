#include "ParticleSpring.h"


ParticleSpring::ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
}

ParticleSpring::~ParticleSpring()
{
}

void ParticleSpring::updateForce(Particule* particule, float duration)
{
	float longueur = (particule->getPosition() - anchorParticle->getPosition()).norme();	// distance entre deux particule
	Vector3D force = (particule->getPosition() - anchorParticle->getPosition()).normalisation() * K * (l0 - longueur);
	particule->addForce(force);
}
