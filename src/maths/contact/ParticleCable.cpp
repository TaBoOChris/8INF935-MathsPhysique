#include "ParticleCable.h"

ParticleCable::ParticleCable(Particule* partA, Particule* partB, float maxLen, float rest) : ParticleLink(partA, partB)
{
	this->maxLen = maxLen;
	this->restitution = rest;
}

void ParticleCable::ajouterContact(std::vector<ParticleContact*> &particleContacts)
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	float distance = (partA->getPosition() - partB->getPosition()).norme();
	if (distance < partB->getRayon() + partA->getRayon() + 0.05f) {
		// Crée un particuleContact si la distance entre deux particules est inférieure à la somme de leurs rayons
		ParticleContact* tmp;
		tmp = new ParticleContact(partA, partB, this->restitution);
		tmp->setPenetration(partA->getRayon() + partB->getRayon() + 0.05f - distance);
		particleContacts.push_back(tmp);
	}
	if (distance >= maxLen) {
		ParticleContact* tmp = new ParticleContact(partA, partB, 1.0f);
		tmp->setIsRod(true);
		particleContacts.push_back(tmp);
	}
}
