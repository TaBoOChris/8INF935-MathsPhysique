#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

/// <summary>
///  force de traînée /  force de frottement
/// </summary>


class DragGenerator : public ParticuleForceGenerator
{
public:
	// Constructeurs des generateurs de forces de trainee
	DragGenerator();
	// Constructeurs des generateurs de forces de trainee
	DragGenerator(float k1, float k2);
	// Methode de mise a jour des forces execees sur les particules
	virtual void updateForce(Particule* particule, float duration);

private:
	// Constantes frottement 
	float k1;
	// Constantes frottement
	float k2;
};
