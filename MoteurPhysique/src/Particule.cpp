#include "Particule.h"

Particule::Particule()
{
<<<<<<< HEAD
	this->inverseMasse = 1.0f;
	this->frottement = 1.0f;
=======
	this->inverseMasse = 100000000000000.0f;
	this->frottement = 0.0f;
>>>>>>> c6e230d2b582d105b0911cebbd8878cabe6d4928
}

Particule::Particule(float invMasse)
{
	this->inverseMasse = invMasse;
	this->frottement = 1.0f;
}

Particule::Particule(float invMasse, float frott)
{
	this->inverseMasse = invMasse;
	this->frottement = frott;
}

<<<<<<< HEAD
Particule::Particule(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration)
{
	this->position = initialPosition;
	this->vitesse = initialVitesse;
	this->acceleration = initialAcceleration;
	this->inverseMasse = 1.0f;
	this->frottement = 1.0f;
}

=======
>>>>>>> c6e230d2b582d105b0911cebbd8878cabe6d4928
float Particule::getInverseMasse()
{
	return this->inverseMasse;
}

Vector3D Particule::getPosition()
{
	return this->position;
}

void Particule::setInverseMasse(float invM)
{
	this->inverseMasse = invM;
}

void Particule::setFrottement(float frott)
{
	this->frottement = frott;
}

//pour accélération, position et vitesse, on applique les formules physiques vues en cours
{
<<<<<<< HEAD
	this->acceleration =  this->appliedForce * this->inverseMasse;
=======
	this->acceleration = this->appliedForce * this->inverseMasse;
>>>>>>> c6e230d2b582d105b0911cebbd8878cabe6d4928
}


void Particule::updateVitesse(float temps)
{
	this->vitesse = this->vitesse * pow(this->frottement, temps) + this->acceleration * temps;
}

void Particule::updatePosition(float temps)
{
	this->position = this->position + this->vitesse * temps + this->acceleration * pow(temps, 2) * 0.5f;
}

//on update chaque vecteur en fonction des vecteurs de l'instant précédent
void Particule::integrer(float temps)
{
	updatePosition(temps);
	updateVitesse(temps);
	updateAcceleration();
}
