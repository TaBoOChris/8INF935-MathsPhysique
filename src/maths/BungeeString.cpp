#include "BungeeString.h"

BungeeString::BungeeString(Particule anchorParticle, float constElast, float lenRepos)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
}

BungeeString::~BungeeString()
{
}

void BungeeString::updateForce(Particule* particule)
{	
	float longueur = (particule->getPosition() - anchorParticle.getPosition()).norme();
	if (l0 <= longueur) return;
	Vector3D force = K * (l0 - longueur);
	particule->addForce(force);
}
