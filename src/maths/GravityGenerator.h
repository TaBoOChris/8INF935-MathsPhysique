#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

class GravityGenerator : public ParticuleForceGenerator
{
public:
	GravityGenerator();
	GravityGenerator(Vector3D new_gravity);
	~GravityGenerator();
	void updateForce(Particule* particule, float duration);

private:
	Vector3D gravite;
};
