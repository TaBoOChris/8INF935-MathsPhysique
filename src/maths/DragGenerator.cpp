#include "DragGenerator.h"

DragGenerator::DragGenerator()
{
	this->k1 = 1.0f;
	this->k2 = 1.0f;
}

DragGenerator::DragGenerator(float k1, float k2) {
	this->k1 = k1;
	this->k2 = k2;
}

DragGenerator::~DragGenerator()
{
}

void DragGenerator::updateForce(Particule* particule, float duration) {
	float coef = -(this->k1 * particule->getVitesse().norme + this->k2 * particule->getVitesse().norme * particule->getVitesse().norme);

	particule->addForce(coef * particule->getVitesse());

}
