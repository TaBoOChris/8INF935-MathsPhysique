#pragma once
#include "Vecteur3D.h"
#include "ParticuleForceGenerator.h"


/// <summary>
/// Les particules cherche � se rapprocher si elle sont �loign�
/// </summary>



class BungeeString : public ParticuleForceGenerator
{

public:
	BungeeString();
	BungeeString(Particule* anchorParticle, float constElast, float lenRepos);
	~BungeeString();

	void updateForce(Particule* particule, float duration);	// update the force
	
private:
	Particule* anchorParticle;
	float K;	// constante d'�lasticit�
	float l0;	// longeur repos
};

