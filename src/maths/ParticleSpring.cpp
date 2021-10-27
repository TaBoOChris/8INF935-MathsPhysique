#include "ParticleSpring.h"


ParticleSpring::ParticleSpring(Particule anchorParticle, float constElast, float lenRepos)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
}

ParticleSpring::~ParticleSpring()
{
}

void ParticleSpring::updateForce(Particule* particule)
{
	float longueur = (particule->getPosition() - anchorParticle.getPosition()).norme();
	Vector3D force = K * (l0 - longueur);
	particule->addForce(force);
}
