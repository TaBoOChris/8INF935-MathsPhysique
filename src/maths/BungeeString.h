#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

class BungeeString : public ParticuleForceGenerator
{
public:
	BungeeString(Particule anchorParticle, float constElast, float lenRepos);
	~BungeeString();
	virtual void updateForce(Particule* particule);

private:
	Particule anchorParticle;
	float K;
	float l0;
};

