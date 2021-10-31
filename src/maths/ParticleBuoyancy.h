#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"


/// <summary>
/// Flotabilité de la particule 
/// </summary>

class ParticleBuoyancy : public ParticuleForceGenerator
{
public:
	ParticleBuoyancy(float maxDepth, float objVolume, float hauteurLiquide, float density);
	void updateForce(Particule* particule, float duration);

private:
	float maxDepth;
	float objVolume;
	float hauteurLiquide;
	float density;
};

