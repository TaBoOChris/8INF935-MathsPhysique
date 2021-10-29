#include "ParticleRod.h"

ParticleRod::ParticleRod(Particule* partA, Particule* partB, float len) : ParticleLink(partA, partB)
{
	this->len = len;
}

void ParticleRod::addContact()
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	Vector3D contactNormal = (partA->getPosition() - partB->getPosition()).normalisation();
	new ParticleContact(partA, partB, 0, contactNormal);
}
