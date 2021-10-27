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
	~ParticleBuoyancy();
	virtual void updateForce(Particule* particule);

private:
	float maxDepth;
	float objVolume;
	float hauteurLiquide;
	float density;
};

