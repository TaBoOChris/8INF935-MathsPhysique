#pragma once
#include "../Particule.h"

class ParticuleContact
{
private:

	Particule* particules[2];
	float coeffRestitution;
	Vector3D norme;
	float penetration;

public:

	void resolve(float durée);
	float getVelociteEloignement();
	void resolveImpulsion();
	void resolveInterprenetration();
};

