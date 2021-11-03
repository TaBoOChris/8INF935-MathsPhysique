#pragma once
#include "ParticuleForceGenerator.h"

/// <summary>
/// Comme ParticleSpring mais cette fois, le ressort est ancre a un point de l'espace defini par un vecteur
/// </summary>
class ParticleAnchoredSpring : public ParticuleForceGenerator
{
public:
	// Constructeur du ressort ancre
	ParticleAnchoredSpring(Vector3D anchor, float constElast, float lenRepos);
	// Methode de mise a jour des forces execees sur la particule
	virtual void updateForce(Particule* particule, float duration);

private:
	// Point de l'espace, defini par un vector3D, qui constitut le point d'ancrage du ressort
	Vector3D anchor;
	// Constante d'elasticite du ressort
	float K;
	// Longueur au repos du ressort
	float l0;
};

