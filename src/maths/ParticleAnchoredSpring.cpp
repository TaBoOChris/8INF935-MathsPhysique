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

void ParticleAnchoredSpring::updateForce(Particule* particule, float duration)
{



	float longueur = (particule->getPosition() - anchor).norme();	// distance entre deux particule
	//if (longueur <= l0) return;																// si longueur repos < longeur, rien
	Vector3D force = (particule->getPosition() - anchor).normalisation() * K * (l0 - longueur);
	particule->addForce(force);
}
