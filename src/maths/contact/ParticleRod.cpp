#include "ParticleRod.h"

ParticleRod::ParticleRod(Particule* partA, Particule* partB, float len) : ParticleLink(partA, partB)
{
	this->len = len;

}

void ParticleRod::ajouterContact(std::vector<ParticleContact*> &particleContacts) 
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];
	ParticleContact* tmp;
	tmp = new ParticleContact(partA, partB, 0.0f);
	float distance = (partA->getPosition() - partB->getPosition()).norme();
	tmp->setPenetration(this->len - distance);
	particleContacts.push_back(tmp);
	/*ParticleContact* tmp2;
	tmp2 = new ParticleContact(partB, partA, 0.0f);
	float distance2 = (partA->getPosition() - partB->getPosition()).norme();
	tmp2->setPenetration(distance2 - this->len);
	particleContacts.push_back(tmp2);*/
}
