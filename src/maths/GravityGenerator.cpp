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

GravityGenerator::updateForce(Particule* particule, float duration) {
	particule->appliedForce = particule->appliedForce + ((1 / particule->getInverseMasse) * this->gravite);
}
