#include "ParticleRod.h"

ParticleRod::ParticleRod(Particule* partA, Particule* partB, float len) : ParticleLink(partA, partB)
{
	this->len = len;

}

void ParticleRod::ajouterContact(std::vector<ParticleContact*> &particleContacts) 
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	float distance = (partA->getPosition() - partB->getPosition()).norme();
	if (distance == this->len) {
		return;
	}
	ParticleContact* tmp;
	tmp = new ParticleContact(partA, partB, 0.0f);
	tmp->setIsRod(true);
	tmp->setPenetration(this->len - distance);
	particleContacts.push_back(tmp);

}
