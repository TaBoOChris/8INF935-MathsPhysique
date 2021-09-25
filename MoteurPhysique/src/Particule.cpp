#include "Particule.h"

float Particule::getInverseMasse()
{
	return inverseMasse;
}

void Particule::updateAcceleration()
{
	acceleration = inverseMasse * appliedForce;
}


void Particule::updateVitesse(float temps)
{
	vitesse = vitesse * pow(frottement, temps) + acceleration * temps;
}

void Particule::updatePosition(float temps)
{
	position = position + vitesse * temps + acceleration * pow(temps, 2) * 0.5f;
}

void Particule::integrer(float temps)
{
	updatePosition(temps);
	updateVitesse(temps);
	updateAcceleration();
}
