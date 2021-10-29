#include "ParticleCable.h"

ParticleCable::ParticleCable(Particule* partA, Particule* partB, float maxLen, float rest) : ParticleLink(partA, partB)
{
	this->maxLen = maxLen;
	this->restitution = rest;
}

void ParticleCable::ajouterContact()
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	Vector3D contactNormal = (partA->getPosition() - partB->getPosition()).normalisation();
	new ParticleContact(partA, partB, this->restitution, contactNormal);
}
