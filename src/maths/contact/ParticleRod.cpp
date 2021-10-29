#include "ParticleRod.h"

ParticleRod::ParticleRod(Particule* partA, Particule* partB, float len) : ParticleLink(partA, partB)
{
	this->len = len;
}

void ParticleRod::ajouterContact(std::vector<ParticleContact*> &particleContacts) 
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	particleContacts.push_back(new ParticleContact(partA, partB, 1));
}
