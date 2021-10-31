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
	ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos, float lmax);
	virtual void updateForce(Particule* particule, float duration);
	void setLMax(float newLMax);

private:
	Particule *anchorParticle;
	float K;
	float l0;
	float lmax;
};

