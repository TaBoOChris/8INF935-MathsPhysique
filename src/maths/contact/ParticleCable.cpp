#include "ParticleCable.h"

ParticleCable::ParticleCable(Particule* partA, Particule* partB, float maxLen, float rest) : ParticleLink(partA, partB)
{
	this->maxLen = maxLen;
	this->restitution = rest;
}

void ParticleCable::ajouterContact(std::vector<ParticleContact*> particleContacts)
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	if ((partA->getPosition()-partB->getPosition()).norme() >= maxLen) particleContacts.push_back(new ParticleContact(partA, partB, this->restitution));
}
