#include "Particule.h"

Particule::Particule()
{
	this->inverseMasse = 100000000000000.0f;
	this->frottement = 0.0f;
}

Particule::Particule(float invMasse)
{
	this->inverseMasse = invMasse;
	this->frottement = 0.0f;
}

Particule::Particule(float invMasse, float frott)
{
	this->inverseMasse = invMasse;
	this->frottement = frott;
}

float Particule::getInverseMasse()
{
	return this->inverseMasse;
}

void Particule::setInverseMasse(float invM)
{
	this->inverseMasse = invM;
}

void Particule::setFrottement(float frott)
{
	this->frottement = frott;
}

void Particule::updateAcceleration()
{
	this->acceleration = this->inverseMasse * this->appliedForce;
}


void Particule::updateVitesse(float temps)
{
	this->vitesse = this->vitesse * pow(this->frottement, temps) + this->acceleration * temps;
}

void Particule::updatePosition(float temps)
{
	this->position = this->position + this->vitesse * temps + this->acceleration * pow(temps, 2) * 0.5f;
}

void Particule::integrer(float temps)
{
	updatePosition(temps);
	updateVitesse(temps);
	updateAcceleration();
}

