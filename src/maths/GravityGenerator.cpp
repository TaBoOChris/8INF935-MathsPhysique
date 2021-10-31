#include "GravityGenerator.h"

GravityGenerator::GravityGenerator()
{
	this->gravite = Vector3D(0, 0, -9.81f);
}

GravityGenerator::GravityGenerator(Vector3D new_gravity) {
	this->gravite = new_gravity;
}

void GravityGenerator::updateForce(Particule* particule, float duration) {
	
	// if particle has mass, 
	if (particule->getMasse() > 0) {
		particule->addForce(particule->getMasse() * this->gravite);		// we add the force on particle
	}
}
