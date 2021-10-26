#include "Particule.h"

Particule::Particule()
{
	this->masse = 1.0f;
	this->inverseMasse = 1.0f;
	this->frottement = 1.0f;

}

Particule::Particule(float invMasse)
{
	this->inverseMasse = invMasse;
	this->masse = (invMasse == 0) ? -1.0f : 1 / invMasse;
	this->frottement = 1.0f;
}

Particule::Particule(float invMasse, float frott)
{
	this->inverseMasse = invMasse;
	this->masse = (invMasse == 0) ? -1.0f : 1 / invMasse;
	this->frottement = frott;
}


Particule::Particule(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration)
{
	this->position = initialPosition;
	this->vitesse = initialVitesse;
	this->acceleration = initialAcceleration;
	this->inverseMasse = 1.0f;
	this->frottement = 1.0f;
}


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
	this->masse = (invM == 0) ? -1.0f : 1 / invM;
}

void Particule::setInverseMasse(float masse) {
	this->masse = masse;
	this->inverseMasse = (masse == 0) ? this->inverseMasse = -1.0f : this->inverseMasse = 1 / masse;
}

void Particule::setFrottement(float frott)
{
	this->frottement = frott;
}

void Particule::setVitesse(Vector3D vitesse)
{
	this->vitesse = vitesse;
}

float Particule::getMasse() {
	return this->masse;
}

//pour accélération, position et vitesse, on applique les formules physiques vues en cours
void Particule::updateAcceleration()
{
	this->acceleration =  this->accumForce * this->inverseMasse;
	this->accumForce = new Vector3D(0, 0, 0);
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

void Particule::addForce(Vector3D force) {
	this->accumForce = this->accumForce + force;
}
