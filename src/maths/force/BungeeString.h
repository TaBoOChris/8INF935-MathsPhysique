#pragma once
#include "ParticuleForceGenerator.h"


/// <summary>
/// Les particules cherche � se rapprocher si elle sont �loign�
/// </summary>



class BungeeString : public ParticuleForceGenerator
{

public:
	// Constructeurs du ressort
	BungeeString();
	BungeeString(Particule* anchorParticle, float constElast, float lenRepos);

	void updateForce(Particule* particule, float duration);	// Met a jour la force uniquement si la distance entre les particules est plus grande que sa longueur au repos
	
private:
	Particule* anchorParticle; // Particule a laquelle le ressort est ancre
	float K;	// constante d'�lasticit�
	float l0;	// longeur repos
};

