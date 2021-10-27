#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

class ParticleAnchoredSpring : public ParticuleForceGenerator
{
public:
	ParticleAnchoredSpring(Vector3D anchor, float constElast, float lenRepos);
	~ParticleAnchoredSpring();
	virtual void updateForce(Particule* particule, float duration);

private:
	Vector3D anchor;
	float K;
	float l0;
};

