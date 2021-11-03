#pragma once
#include "ParticuleForceGenerator.h"

/// <summary>
/// Simple elastic, les particules cherches tout le temps à ce que leur distance soit proche de l0
/// </summary>
class ParticleSpring : public ParticuleForceGenerator
{
public:
	// Constructeur des ressorts
	ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos);
	// Constructeur du ressorts dans le cadre de notre TP ou les ressorts doivent se comporter comme des cables a partir d'une longueur max
	ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos, float lmax);
	// Methode de mise a jour des forces execees sur les particules
	virtual void updateForce(Particule* particule, float duration);
	// Setter de lmax
	void setLMax(float newLMax);

private:
	// Particule a laquelle le ressort est ancre
	Particule *anchorParticle;
	// Constante d'elasticite du ressort
	float K;
	// Longueur au repos du ressort
	float l0;
	// Longueur maximal du ressort avant qu'il ne se comporte comme un cable
	float lmax;
};

