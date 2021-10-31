#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

/// <summary>
/// Simple elastic, les particule cherche tout le temps à se rapprocher
/// </summary>
class ParticleSpring : public ParticuleForceGenerator
{
public:
	ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos);
	virtual void updateForce(Particule* particule, float duration);

private:
	Particule *anchorParticle;
	float K;
	float l0;
};

