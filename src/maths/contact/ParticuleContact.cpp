#include "ParticuleContact.h"

void ParticuleContact::resolve(float durée)
{
}

float ParticuleContact::getVelociteEloignement()
{
	this->norme = (particules[0]->getPosition() - particules[1]->getPosition()).normalisation();
	
	return (particules[0]->getVitesse() - particules[1]->getVitesse()) * this->norme;
}

void ParticuleContact::resolveImpulsion()
{
}

void ParticuleContact::resolveInterprenetration()
{
}
