#include "GravityGenerator.h"

GravityGenerator::GravityGenerator()
{
}

GravityGenerator::GravityGenerator(Vector3D new_gravity) {
	this->gravite = new_gravity;
}

GravityGenerator::~GravityGenerator()
{
}

void GravityGenerator::updateForce(Particule* particule, float duration) {
	particule->addForce(particule->getMasse * this->gravite);
}
