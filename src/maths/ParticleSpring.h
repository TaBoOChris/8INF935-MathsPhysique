#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

class ParticleSpring : public ParticuleForceGenerator
{
public:
	ParticleSpring(Particule anchorParticle, float constElast, float lenRepos);
	~ParticleSpring();
	virtual void updateForce(Particule* particule);

private:
	Particule anchorParticle;
	float K;
	float l0;
};

