#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"

/// <summary>
///  force de traînée /  force de frottement
/// </summary>


class DragGenerator : public ParticuleForceGenerator
{
public:
	DragGenerator();
	DragGenerator(float k1, float k2);
	~DragGenerator();
	virtual void updateForce(Particule* particule, float duration);

private:
	float k1;
	float k2;
};
