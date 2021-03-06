#pragma once
#include "ParticuleForceGenerator.h"

class GravityGenerator : public ParticuleForceGenerator
{

public:

	GravityGenerator();
	GravityGenerator(Vector3D new_gravity);

	void updateForce(Particule* particule, float duration);	// update the force

private:
	Vector3D gravite;
};
